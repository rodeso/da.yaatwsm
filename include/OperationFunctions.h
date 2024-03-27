#ifndef YAATWSM_OPERATIONFUNCTIONS_H
#define YAATWSM_OPERATIONFUNCTIONS_H

#include "Include.h"
#include "Node.h"
#include "Graph.h"

/**
 * @brief Class that represents the multiple functions related to the main operations of the system.
 */

class OperationFunctions {
    private:

    public:
        /**
        * @brief Algorithm that calculates flow for the graph
        * @details Complexity O(V²E²)
        */
        static void edmondsKarp(Graph<Node> *g, const Node &source, const Node &target);
        /**
        * @brief Function that calculates the max flow for the entire graph.
        * @details Complexity O(V²E²)
        */
        static Graph<Node> maxFlow(Graph<Node>& graph);
        /**
        * @brief Function that analysis the max flow for a given city.
        * @details Complexity O(V²E²)
        */
        static double maxFlowOfCity(Graph<Node>& graph, Node const &a);
        /**
        * @brief Function that returns the max flow for all the existing cities in the selected data folder.
        * @details Complexity O(V²E²)
        */
        static double maxFlowPerCity(Graph<Node>& graph);
        /**
        * @brief Function that evaluates which cities cannot be supplied with the desired water rate level, indicating the amount of water flow in deficit.
        * @details Complexity O(V²E²)
        */
        static vector<pair<Node, double>> supplyAndDemand(Graph<Node>& graph);
        /**
        * @brief Function that calculates the max value and the average of all differences between the flow and the capacity of all the pipes (edges).
        * @details Complexity O(V²E²)
        */
        static pair<double,double> averageAndMaxOfDifferenceOfCapAndFlow(Graph<Node>& graph);
        /**
        * @brief Function that calculates the variance of all differences between the flow and the capacity of all the pipes (edges).
        * @details Complexity O(V²E²)
        */
        static double variance(Graph<Node>& graph);
        /**
        * @brief Function that calculates the changes in the cities water supply after the deactivation of either a Reservoir or a Pumping Station. Calculates affected cities and water supply deficits.
        * @details Complexity O(V²E²)
        */
        static void deactivation(Graph<Node>& graph, Node a);
        /**
        * @brief Function that calculates the affected cities and its water supply deficits after the deactivation/rupture of a given pipeline.
        * @details Complexity O(V²E²)
        */
        static void criticalPipesOfCity(Graph<Node>& graph, Node city);
        /**
        * @brief Function that calculates the pipelines that, if deactivated or ruptured, affect the water supply of a given city.
        * @details Complexity O(V²E²)
        */
        static void citiesOfCriticalPipe(Graph<Node>& graph, Node start, Node end);
};


#endif //YAATWSM_OPERATIONFUNCTIONS_H
