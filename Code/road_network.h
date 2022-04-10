#pragma once
#include <map>
#include <vector>
#include "stdlib.h"

class RoadNetwork {
    public:
        /* The destructor for the RoadNetwork class
        */
        ~RoadNetwork();
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
        shortestPath find the distances between the start node and the end node.
        Returns a string consist of the node visted in the path
        */
        std::string shortestPath(int start, int end);
        
    private:
        //nodes
        std::vector<Node*> Nodelist_;
        //adjacency list
        list<Edge> *adjLists;
};
