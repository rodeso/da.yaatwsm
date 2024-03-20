#ifndef YAATWSM_MENU_H
#define YAATWSM_MENU_H
#include "Include.h"
#include "Graph.h"
#include "Node.h"
#include "ReadFunctions.h"
#include "OperationFunctions.h"


class Menu {

    private:
        Graph<Node> graph;

    public:
        void run();
        void case1(Graph<Node> &graph, unordered_map<string, string> &citydict);
        void case2(Graph<Node> &graph);







};


#endif //YAATWSM_MENU_H
