#ifndef YAATWSM_READFUNCTIONS_H
#define YAATWSM_READFUNCTIONS_H
#include "Include.h"
#include "Graph.h"
#include "Node.h"


class ReadFunctions {
    private:

    public:
        static vector<Node> readReservoirs(string pathname);
        static vector<Node> readCities(string pathname);
        static vector<Node> readStations(string pathname);
        static void readPipes(Graph<Node>& graph, string pathname);

};



#endif //YAATWSM_READFUNCTIONS_H
