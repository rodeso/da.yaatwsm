#ifndef YAATWSM_OPERATIONFUNCTIONS_H
#define YAATWSM_OPERATIONFUNCTIONS_H

#include "Include.h"
#include "Node.h"
#include "Graph.h"

class OperationFunctions {
    private:

    public:
        static Graph<Node> maxFlow(Graph<Node>& graph);
        static double maxFlowOfCity(Graph<Node>& graph, Node const &a);
        static double maxFlowPerCity(Graph<Node>& graph);
        static vector<pair<Node, double>> supplyAndDemand(Graph<Node>& graph);
        static void deactivation(Graph<Node>& graph, Node a);

};


#endif //YAATWSM_OPERATIONFUNCTIONS_H
