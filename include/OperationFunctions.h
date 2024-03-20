#ifndef YAATWSM_OPERATIONFUNCTIONS_H
#define YAATWSM_OPERATIONFUNCTIONS_H

#include "Include.h"
#include "Node.h"
#include "Graph.h"

class OperationFunctions {
    private:

    public:
        static double maxFlowOfCity(Graph<Node>& graph, Node a);
        static void maxFlowPerCity(Graph<Node>& graph);


};


#endif //YAATWSM_OPERATIONFUNCTIONS_H
