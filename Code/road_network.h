#pragma once
#include <map>
#include <vector>
#include "stdlib.h"


#include "data_correction.h"

class RoadNetwork {
    public:
        /* The constructor for the RoadNetwork class
        */
        RoadNetwork(std::map<int, Coordinate> nodeData, std::map<int, EdgeData> edgeData);
        /* add node to the graph
        */
        void addNode(int id, int x, int y);
        /* add edge to the adjacency list
        */
        void addEdge(Node start, Node end, double distance);
        class Node{
            public:
            int NodeID_;
            int x_;
            int y_;
        };
        class Edge{
            public:
            Node* start;
            Node* end;
            double distance;
        };
        /*
        @param the data contains information about the edgeData
        distance function finds the distances between two connected network nodes and sort them into a vector
        Returns a vector of double (distances) of any two nodes that are connected
        Helper for the shortestPath function
        */
        std::vector<double> distance(std::map<int, EdgeData> data);
        /*
        shortestPath comapres the distances between two nodes and finding the start and end node which has the shortest path
        Returns a pair of int with the first being the start nodeID and the second is the end nodeID
        */
        std::pair<int, int> shortestPath();
        
    private:
        //nodes
        std::vector<Node*> Nodelist_;
        //adjacency list
        list<Edge> *adjLists;
};
