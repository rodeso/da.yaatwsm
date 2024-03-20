#include "../include/Menu.h"


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
        cout << string(LINE_SIZE_, '-') << endl;
        cout << "Loading data contents..." << endl;
        cout << string(LINE_SIZE_, '-') << endl;
        for (auto n : graph.getVertexSet()) {
            n->getInfo().print();
        }
        cout << "Loading menu..." << endl;
        cout << string(LINE_SIZE_, '-') << endl;
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
        cout << string(LINE_SIZE_, '-') << endl;
        cout << endl;
        if (decision.size() != 1) {
            cout << "Invalid input. Please enter a number between 0 and 7: " << endl;
            continue;
        }
        switch (decision[0]) {
            case '1':
                case1();
                sleep(5);
                break;
            case '2':
                case2();
                break;
            case '3':
                case3();
                break;
            case '4':
                case4();
                break;
            case '5':
                case5();
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


void Menu::case1() {
    string city;
    cout << "Please insert the name of the city: ";
    getline(cin,city);
    Node a('d', "", 0, (citydict[city]), "", 0, 0);
    cout << "Maximum amount of reachable water in " << city << " is " << OperationFunctions::maxFlowOfCity(graph, a) << endl;
}

void Menu::case2() {
    OperationFunctions::maxFlowPerCity(graph);
}

void Menu::case3() {
    vector<pair<Node, double>> res = OperationFunctions::supplyAndDemand(graph);
    if (res.size() == 0) {
        cout << "All cities are supplied!";
    }
    else {
        cout << "The cities that cannot be supplied by the desired water rate level are listed bellow, with the amount of water flow in deficit." << endl;
        for (auto t : res) {
            cout << t.first.getCode() << " --> " << t.second << endl;
        }
    }
}
void Menu::case4() {} //TODO LATER

void Menu::case5() {
    string reservoirCode;
    cout << "Please insert the code of the reservoir: ";
    getline(cin,reservoirCode);
    Node del('d', "", 0, reservoirCode, "", 0, 0);
    OperationFunctions::reservoirDeactivation(graph, del);
}
