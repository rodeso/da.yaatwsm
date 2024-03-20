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
        unordered_map<string,string> citydict;

    public:
        void run();
        void case1();
        void case2();
        void case3();
        void case4();
        void case5();
        void case6();
        void case7();







};


#endif //YAATWSM_MENU_H
