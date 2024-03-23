
#include "../include/OperationFunctions.h"



//------------- Edmonds Karp ----------------------------------------------------------------------------------------------------------------------------------------------------


template <class Node>
bool findAugmentingPaths(Graph<Node> *g, Vertex<Node> *s, Vertex<Node> *t) {

    for(auto v : g->getVertexSet()) {v->setVisited(false);}

    s->setVisited(true);
    std::queue<Vertex<Node>*> q;
    q.push(s);
    while(!q.empty() && !t->isVisited()) {
        auto v = q.front();
        q.pop();
        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    return t->isVisited();
}

template <class Node>
double findMinResidualAlongPath(Vertex<Node>* s, Vertex<Node>* t) {
    double f = INT_MAX;
    for (auto v = t; v != s;) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}

template <class Node>
void testAndVisit(std::queue<Vertex<Node>*> &q, Edge<Node>* e, Vertex<Node>* w, double residual) {
    if (!w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

template <class Node>
void augmentFlowAlongPath(Vertex<Node>* s, Vertex<Node>* t, double f) {
    for (auto v = t; v != s;) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}


void edmondsKarp(Graph<Node> *g, Node const &source, Node const &target) {
    Vertex<Node>* s = g->findVertex(source);
    Vertex<Node>* t = g->findVertex(target);

    if (s == nullptr || t == nullptr || s == t) {
        cerr << "Error: Invalid source and/or target vertex";
    }

    for (auto v : g->getVertexSet()) {
        for (auto e : v->getAdj()) {
            e->setFlow(0);
        }
    }

    while (findAugmentingPaths(g, s, t)) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}



//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Graph<Node> OperationFunctions::maxFlow(Graph<Node>& graph) {
    Graph<Node> graphCopy;
    graphCopy = graph.getCopy();

    Node SuperSource('s', "superSource", 0, "R_0", "superSource", INT_MAX, 0);
    Node SuperSink('t', "superSink", 0, "C_0", "superSink", 0, INT_MAX);

    graphCopy.addVertex(SuperSource);
    graphCopy.addVertex(SuperSink);
    for (auto v : graphCopy.getVertexSet()) {
        if (v->getInfo().isSource()) {
            graphCopy.addEdge(SuperSource, v->getInfo(), v->getInfo().getQuantity()); //Source Pipes are limited by Quantity??
            continue;
        }
        if (v->getInfo().isSink()) {
            graphCopy.addEdge(v->getInfo(), SuperSink, v->getInfo().getDemand()); //Sink Pipes are limited by Demand??
            continue;
        }
    }

    edmondsKarp(&graphCopy, SuperSource,SuperSink);

    return graphCopy;
}



double OperationFunctions::maxFlowOfCity(Graph<Node>& graph, Node const &a) {
    Graph<Node> graphCopy;
    graphCopy = maxFlow(graph);
    auto t = graphCopy.findVertex(a);
    for (auto e : t->getAdj()) {
        if ("C_0" == e->getDest()->getInfo().getCode()) {
            return e->getFlow();
        }
    }
    return 0;
}



double OperationFunctions::maxFlowPerCity(Graph<Node>& graph) {
    double max = 0.0;
    Graph<Node> graphCopy;
    graphCopy = maxFlow(graph);
    for (auto t : graphCopy.getVertexSet()) {
        if (t->getInfo().isSink() && t->getInfo().getCode() != "C_0") {
            for (auto e : t->getAdj()) {
                if ("C_0" == e->getDest()->getInfo().getCode()) {
                    cout << t->getInfo().getName() << " --> " << e->getFlow() << endl;
                    max += e->getFlow();
                }
            }
        }
    }
    return max;
}



vector<pair<Node, double>> OperationFunctions::supplyAndDemand(Graph<Node>& graph) {
    vector<pair<Node, double>> res;
    Graph<Node> graphCopy;
    graphCopy = maxFlow(graph);
    for (auto t : graphCopy.getVertexSet()) {
        if (t->getInfo().isSink() && t->getInfo().getCode() != "C_0") {
            for (auto e : t->getAdj()) {
                if ("C_0" == e->getDest()->getInfo().getCode()) {
                    if (e->getFlow() != t->getInfo().getDemand()) {
                        pair<Node,double> a = make_pair(t->getInfo(), t->getInfo().getDemand() - e->getFlow());
                        res.push_back(a);

                    }
                }
            }
        }
    }
    return res;
}

//MAYBE????
void OperationFunctions::deactivation(Graph<Node>& graph, Node a) {

    Graph<Node> graphCopy1 = graph.getCopy();
    graphCopy1.removeVertex(a);
    auto original = supplyAndDemand(graph);
    auto res = supplyAndDemand(graphCopy1);
    double diff = 0;
    if (res.empty()) { cerr << "Error: WHAT??\n";}

    for (auto b : res) {
        double bus = 0;
        bool hasOriginalDeficit = false;
        for (auto c : original) {
            if (b.first.getCode() == c.first.getCode()) {
                hasOriginalDeficit = true;
                bus = c.second;
            }
        }
        if (hasOriginalDeficit) {
            diff = b.second - bus;
        }
        else {
            diff = b.second;
        }
        if (diff > 0) {
            cout << b.first.getCode() << " (" << b.first.getName() << ")  -->  Original deficit: " << bus << "  -->  Deficit after " << a.getCode() << "'s deactivation: " << bus+diff << " (difference of " << diff << ")" << endl;
        }

    }
}

void OperationFunctions::citiesOfCriticalPipe(Graph<Node>& graph, Node start, Node end) {
    Graph<Node> graphAfterEdgeRemoval = graph.getCopy();
    graphAfterEdgeRemoval.removeEdge(start, end);
    auto original = supplyAndDemand(graph);
    auto res = supplyAndDemand(graphAfterEdgeRemoval);
    double diff = 0;
    if (res.empty()) { cerr << "Error: WHAT??\n";}

     for (auto b : res) {
        double bus = 0;
        bool hasOriginalDeficit = false;
        for (auto c : original) {
            if (b.first.getCode() == c.first.getCode()) {
                hasOriginalDeficit = true;
                bus = c.second;
            }
        }
        if (hasOriginalDeficit) {
            diff = b.second - bus;
        }
        else {
            diff = b.second;
        }
        if (diff > 0) {
            cout << b.first.getCode() << " (" << b.first.getName() << ")  -->  Original deficit: " << bus << "  -->  Deficit after removal of pipe from " << start.getCode() << " to " << end.getCode() << ": " << bus + diff << " (difference of " << diff << ")" << endl;
        }
    }
}


void OperationFunctions::criticalPipesOfCity(Graph<Node> &graph, Node city) {
    //find max flow of city
    double originalFlowOfCity = maxFlowOfCity(graph, city);
    //set all edges to unselected
    for (auto vert : graph.getVertexSet()) {
        for (auto edge: vert->getAdj()) {
            edge->setSelected(false);
        }
    }
    //test pipe by pipe if it is critical
    for (auto vert : graph.getVertexSet()) {
        for (auto edge : vert->getAdj()) {
            if (!edge->isSelected()) {
                edge->setSelected(true);
                Graph<Node> graphCopy = graph.getCopy();
                graphCopy.removeEdge(vert->getInfo(),edge->getDest()->getInfo());
                auto res = maxFlowOfCity(graphCopy, city);
                if (res < originalFlowOfCity) {
                    cout << "Pipe from " <<  vert->getInfo().getCode() << " to " << edge->getDest()->getInfo().getCode() << " is critical, causing a flow deficit of: " << originalFlowOfCity - res << endl;
                }
            }
        }
    }
}











