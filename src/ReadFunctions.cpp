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
vector<Node> ReadFunctions::readCities(string pathname) {
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
            nodesCities.push_back(Node('t', city, stoi(id), code,"", stoi(population), stod(demand)));
        } else {
            cerr << "Error (301): City Loading Error";
        }
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

void readPipes(Graph<Node>& graph,const string& pathname) {

}


