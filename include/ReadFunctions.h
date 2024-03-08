#ifndef YAATWSM_READFUNCTIONS_H
#define YAATWSM_READFUNCTIONS_H
#include "Include.h"
#include "Graph.h"
#include "Node.h"

template <class T>
class ReadFunctions {
    private:

    public:
        static vector<Node> readReservoirs(const string& pathname);
        static vector<Node> readCities(const string& pathname);
        static vector<Node> readStations(const string& pathname);
        void readPipes(Graph<T>& graph,const string& pathname);

};



#endif //YAATWSM_READFUNCTIONS_H
