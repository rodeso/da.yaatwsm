#ifndef YAATWSM_READFUNCTIONS_H
#define YAATWSM_READFUNCTIONS_H
#include "Include.h"
#include "Graph.h"
#include "Node.h"


class ReadFunctions {
    private:

    public:
        static vector<Node> readReservoirs(string const &pathname);
        static vector<Node> readCities(unordered_map<string,string> &cityDict, string const &pathname);
        static vector<Node> readStations(string const &pathname);
        static void readPipes(Graph<Node>& graph, string const &pathname);
};



#endif //YAATWSM_READFUNCTIONS_H
