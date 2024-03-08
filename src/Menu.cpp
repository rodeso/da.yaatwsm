#include "../include/Menu.h"

int Menu::LINE_SIZE_ = 119;


void Menu::run() {
    // Graph
    graph = Graph<Node>();
    vector<Node> nodeS;
    vector<Node> nodeT;
    vector<Node> nodeU;

    // Load Graph
    while (true) {
        string decision;
        string path;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Welcome to the Water Supply Management Analysis Tool!" << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Select your data folder:" << endl;
        cout << "1 - Madeira." << endl;
        cout << "2 - Mainland Portugal." << endl;
        cout << "3 - Custom." << endl;
        cout << "4 - Exit." << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Please select the task you wish to perform by inputting its number: ";

        while (true) {
            getline(cin, decision);
            cout << endl;
            if (decision.size() != 1) { cout << "Invalid input. Please enter a number between 1 and 4: "; continue;}
            switch (decision[0]) {
                case '1':
                    path = "../csv/Madeira/";

                    goto load;
                case '2':
                    path = "../csv/Mainland Portugal/";
                    goto load;
                case '3':
                    cout << "Please enter the path to the folder containing the csv files: ";
                    getline(cin, path);
                    goto load;
                case '4':
                    cout << "Goodbye!" << endl;
                    exit(0);
                default:
                    cout << "Invalid input. Please enter a number between 1 and 4: ";
                    break;
            }
        }
        load:
        nodeS = ReadFunctions::readReservoirs(path + "Reservoirs.csv");
        nodeT = ReadFunctions::readCities(path + "Cities.csv");
        nodeU = ReadFunctions::readStations(path + "Stations.csv");
        for (const Node &i : nodeS) {
            graph.addVertex(i);
        }
        for (const Node &i : nodeT) {
            graph.addVertex(i);
        }
        for (const Node &i : nodeU) {
            graph.addVertex(i);
        }
        for (auto n : graph.getVertexSet()) {
            n->getInfo().print();
        }
        sleep(5);
        break;
    }
    //Real Menu
    while(true) {
        string decision;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Select your operation:" << endl;
        cout << "1 - Fuck off." << endl;
        cout << "2 - Fuck off." << endl;
        cout << "3 - Custom." << endl;
        cout << "4 - Exit." << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Please select the task you wish to perform by inputting its number: ";

        while (true) {
            getline(cin, decision);
            cout << endl;
            if (decision.size() != 1) { cout << "Invalid input. Please enter a number between 1 and 4: "; continue;}
            switch (decision[0]) {
                case '1':
                    goto end;
                case '2':
                    goto end;
                case '3':
                    cout << "Fuck Off \n";
                    goto end;
                case '4':
                    cout << "Goodbye!" << endl;
                    exit(0);
                default:
                    cout << "Invalid input. Please enter a number between 1 and 4: ";
                    break;
            }
        }
        end:
        cout << "Fucking Off \n";
    }
}