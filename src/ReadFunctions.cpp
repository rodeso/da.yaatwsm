
#include "../include/ReadFunctions.h"
#include "../include/Include.h"

vector<Node> readCities(const string& pathname) {
    vector<Node> nodesCities;

    ifstream file(pathname);
    if (!file.is_open()) {
        cerr << "Error (205): Wrong Pathname";
        return nodesCities;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string city, code, id, population, demand;


        if (getline(ss, city, ',') && getline(ss, id, ',') && getline(ss, code, ',') && getline(ss, demand, ',') && getline(ss, population, ',')) {
            nodesCities.push_back(Node('t', city, stoi(id), code,"", stoi(population), stod(demand)));
        } else {
            cerr << "Error (303): City Loading Error";
        }
    }

    file.close();
    return nodesCities;
}

vector<Node> readReservoirs(const string& pathname) {
    vector<Node> nodesReservoirs;

    ifstream file(pathname);
    if (!file.is_open()) {
        cerr << "Error (205): Wrong Pathname";
        return nodesReservoirs;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string reservoir, municipality, code, id, maximumDelivery;


        if (getline(ss, reservoir, ',') && getline(ss, municipality, ',') && getline(ss, id, ',') && getline(ss, code, ',') && getline(ss, maximumDelivery, ',')) {
            nodesReservoirs.push_back(Node('s', reservoir, stoi(id), code, municipality, stoi(maximumDelivery), 0));
        } else {
            cerr << "Error (303): Reservoir Loading Error";
        }
    }

    file.close();
    return nodesReservoirs;


}


vector<Node> readStations(const string& pathname) {

}


void readPipes(Graph<T>& graph,const string& pathname) {

}
