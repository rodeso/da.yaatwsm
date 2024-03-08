
#include "../include/ReadFunctions.h"
#include "../include/Include.h"

vector<Node> readCities(const string& pathname) {
    vector<Node> nodesCities;

    ifstream file(pathname);
    if (!file.is_open()) {
        cout << "Error: Wrong Pathname";
        return nodesCities;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string city, code, id, population, demand;


        if (getline(ss, city, ',') && getline(ss, id, ',') && getline(ss, code, ',') && getline(ss, demand, ',') && getline(ss, population, ',')) {
            nodesCities.push_back(Node('t', city, stoi(id), code, stod(demand), stoi(population)));
        } else {
            cerr << "Error (303): City Loading Error";
        }
    }

    file.close();
    return nodesCities;
}
