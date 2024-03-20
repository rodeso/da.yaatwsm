#ifndef YAATWSM_MENU_H
#define YAATWSM_MENU_H
#include "Include.h"
#include "Graph.h"
#include "Node.h"
#include "ReadFunctions.h"


class Menu {

    private:
        static int LINE_SIZE_;
        Graph<Node> graph;

    public:
        void run();
        void function1(Graph<Node> &graph, unordered_map<string, string> &citydict);







};


#endif //YAATWSM_MENU_H
