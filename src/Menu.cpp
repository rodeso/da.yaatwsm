#include "../include/Menu.h"

int Menu::LINE_SIZE_ = 119;


void Menu::run() {
    // Graph
    graph = Graph<Node>();
    vector<Node> nodeS;
    vector<Node> nodeT;
    vector<Node> nodeU;
    unordered_map<string,string> citydict;

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
        cout << "0 - Exit." << endl;
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
                case '0':
                    cout << "Goodbye!" << endl;
                    exit(0);
                default:
                    cout << "Invalid input. Please enter a number between 1 and 4: ";
                    break;
            }
        }
        load:
        nodeS = ReadFunctions::readReservoirs(path + "Reservoirs.csv");
        nodeT = ReadFunctions::readCities(citydict, path + "Cities.csv");
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
        ReadFunctions::readPipes(graph, path + "Pipes.csv");
        sleep(5);
        break;
    }
    //Real Menu
    while (true) {
        string decision;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Select your operation:" << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "1 - Maximum amount of reachable water of a given city." << endl; //T2.1
        cout << "2 - List of maximum amount of reachable water per city." << endl; //T2.1
        cout << "3 - Water reservoirs supply and demand status." << endl; //T2.2
        cout << "4 - Network balancing tool." << endl; //T2.3
        cout << "5 - Water reservoirs deactivation analysis." << endl; //T3.1
        cout << "6 - Pumping stations deactivation analysis." << endl; //T3.2
        cout << "7 - Critical pipes analysis." << endl; //T3.3
        cout << "0 - Exit." << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Please select the task you wish to perform by inputting its number: ";
        getline(cin, decision);
        cout << endl;
        if (decision.size() != 1) {
            cout << "Invalid input. Please enter a number between 0 and 7: " << endl;
            continue;
        }
        switch (decision[0]) {
            case '1':
                function1(graph, citydict);
                sleep(5);
                break;
                //to be made
            case '2':
                //to be made
                break;
            case '3':
                //to be made
                break;
            case '4':
                //to be made
                break;
            case '5':
                //to be made
                break;
            case '6':
                //to be made
                break;
            case '7':
                //to be made
                break;
            case '0':
                cout << "Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid input. Please enter a number between 0 and 7: " << endl;
                break;
        }


    }
}



void Menu::function1(Graph<Node> &graph, unordered_map<string,string> &citydict) {
    string city;
    cout << "Please insert the name of the city: ";
    getline(cin,city);
    Node a('d', "", 0, (citydict[city]), "", 0, 0);
    auto vertexA = graph.findVertex(a);
    //cout << vertexA->getInfo().getType() << endl;
}