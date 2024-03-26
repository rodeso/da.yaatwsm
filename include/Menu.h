#ifndef YAATWSM_MENU_H
#define YAATWSM_MENU_H
#include "Include.h"
#include "Graph.h"
#include "Node.h"
#include "ReadFunctions.h"
#include "OperationFunctions.h"

/**
 * @brief Class that represents the system menus' interface and all of its stored data.
 */

class Menu {

    private:
        /**
        * @brief Graph structure.
        */
        Graph<Node> graph;
        /**
        * @brief Dictionary to help relate the names of the cities with its respective code.
        */
        unordered_map<string,string> cityDict;

    public:
        void run();
        void case1();
        void case2();
        void case3();
        void case4();
        void case5();
        void case6();
        void case7();
        void case8();


};


#endif //YAATWSM_MENU_H
