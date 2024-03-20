#include "../include/ReadFunctions.h"


vector<Node> ReadFunctions::readReservoirs(string pathname) {
    vector<Node> nodesReservoirs;

    ifstream file(pathname);
    if (!file.is_open()) {
        cerr << "Error (204): Wrong Path";
        return nodesReservoirs;
    }
    string fline;
    getline(file, fline);

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string reservoir, municipality, code, id, maximumDelivery;


        if (getline(ss, reservoir, ',') && getline(ss, municipality, ',') && getline(ss, id, ',') && getline(ss, code, ',') && getline(ss, maximumDelivery, ',')) {
            nodesReservoirs.push_back(Node('s', reservoir, stoi(id), code, municipality, stoi(maximumDelivery), 0));
        } else {
            cerr << "Error (302): Reservoir Loading Error";
        }
    }

    file.close();
    return nodesReservoirs;
}
vector<Node> ReadFunctions::readCities(unordered_map<string, string> &citydict, string pathname) {
    vector<Node> nodesCities;

    ifstream file(pathname);
    if (!file.is_open()) {
        cerr << "Error (205): Wrong Path";
        return nodesCities;
    }
    string fline;
    getline(file, fline);

    string line;

    while (getline(file, line)) {
        istringstream ss(line);
        string city, code, id, population, demand;

        if (getline(ss, city, ',') && getline(ss, id, ',') && getline(ss, code, ',') && getline(ss, demand, ',') && getline(ss, population, ',')) {
            nodesCities.push_back(Node('t', Node::removeCarriageReturn(city), stoi(id), code,"", stoi(population), stod(demand)));
            citydict[Node::removeCarriageReturn(city)] = Node::removeCarriageReturn(code);
        } else {
            cerr << "Error (301): City Loading Error";
        }
    }
    if (citydict.size() == 0) {
        cerr << "Error (701): Map Empty!";
    }

    file.close();
    return nodesCities;
}

vector<Node> ReadFunctions::readStations(string pathname) {
    vector<Node> nodesStations;

    ifstream file(pathname);
    if (!file.is_open()) {
        cerr << "Error (206): Wrong Path";
        return nodesStations;
    }
    string fline;
    getline(file, fline);

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string id, code;
        if (getline(ss, id, ',') && getline(ss, code, ',')) {
            nodesStations.push_back(Node('u', "", stoi(id), code, "", 0, 0));
        } else {
            cerr << "Error (303): Station Loading Error";
        }
    }
    file.close();
    return nodesStations;
}

void ReadFunctions::readPipes(Graph<Node> &graph, std::string pathname) {
    ifstream file(pathname);
    if (!file.is_open()) {
        cerr << "Error (207): Wrong Path";
        return;
    }
    string fline;
    getline(file, fline);

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string start, end, capacity, direction;
        if (getline(ss, start, ',') && getline(ss, end, ',') && getline(ss, capacity, ',') && getline(ss, direction, ',')) {
            //cout << Node::stringToHex(start) << endl;
            //cout << Node::stringToHex(end) << endl;

            Node a('d', "", 0, start, "", 0, 0);
            Node b('d', "", 0, end, "", 0, 0);

            auto vertexA = graph.findVertex(a);
            auto vertexB = graph.findVertex(b);

            if (vertexA && vertexB) {
                graph.addEdge(vertexA->getInfo(), vertexB->getInfo(), stoi(capacity));

                int d = stoi(direction);
                if (d == 0) {
                    graph.addEdge(vertexB->getInfo(), vertexA->getInfo(), stoi(capacity));
                }
            } else {
                cerr << "Error (501): Vertex not found in the graph" << endl;
            }
        } else {
            cerr << "Error (304): Pipe Loading Error";
        }
    }
    file.close();
}


