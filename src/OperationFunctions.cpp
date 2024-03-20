
#include "../include/OperationFunctions.h"



//------------- Edmonds Karp ----------------------------------------------------------------------------------------------------------------------------------------------------


template <class Node>
bool findAugmentingPaths(Graph<Node> *g, Vertex<Node>* s, Vertex<Node>* t) {

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

void edmondsKarp(Graph<Node> *g, Node source, Node target) {
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




double OperationFunctions::maxFlowOfCity(Graph<Node>& graph, Node a) {
    Graph<Node> graphCopy;
    graphCopy = graph.getCopy();

    Node SuperSource('s', "supersource", 0, "R_0", "supersource", INT_MAX, 0);
    Node SuperSink('t', "supersink", 0, "C_0", "supersink", 0, INT_MAX);

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
    auto t = graphCopy.findVertex(a);
    for (auto e : t->getAdj()) {
        if (SuperSink.getCode() == e->getDest()->getInfo().getCode()) {
            return e->getFlow();
        }
    }
    return 0;
}

void OperationFunctions::maxFlowPerCity(Graph<Node>& graph) {
    Graph<Node> graphCopy;
    graphCopy = graph.getCopy();

    Node SuperSource('s', "supersource", 0, "R_0", "supersource", INT_MAX, 0);
    Node SuperSink('t', "supersink", 0, "C_0", "supersink", 0, INT_MAX);

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
    for (auto t : graphCopy.getVertexSet()) {
        if (t->getInfo().isSink() && t->getInfo().getCode() != "C_0") {
            for (auto e : t->getAdj()) {
                if (SuperSink.getCode() == e->getDest()->getInfo().getCode()) {
                    cout << t->getInfo().getName() << " --> " << e->getFlow() << endl;
                }
            }
        }
    }
}


