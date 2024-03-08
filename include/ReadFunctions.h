#ifndef YAATWSM_READFUNCTIONS_H
#define YAATWSM_READFUNCTIONS_H


#include "Graph.h"
#include "Node.h"

template <class T>
class ReadFunctions {
    private:

    public:
        vector<Node> readCities(const string& pathname);
        vector<Node> readReservoirs(const string& pathname);
        vector<Node> readStations(const string& pathname);
        void readPipes(Graph<T>& graph,const string& pathname);

};

#endif //YAATWSM_READFUNCTIONS_H
