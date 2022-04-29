#pragma once

#include <map>
#include <vector>
#include <string>
#include "cs225/PNG.h"

using namespace std;

class RoadNetwork {
    public:
        /*
        Constructor that sets the default value of a RoadNetwork class
        */
        RoadNetwork() { Nodelist_ = vector<Node*>(); x_= 0; y_ = 0;}

        /*
        Destructor for the RoadNetwork class
        */
        ~RoadNetwork();

        /*
        Helper function for the destructor
        */
        void clear();

        /*
        Edge nested class inside the RoadNetwork, stores the start node id, end node id and the distance between the two
        */
        class Edge {
            public:
            Edge(int start_, int end_, double distance_) {
                start = start_;
                end = end_;
                distance = distance_;
            }
            int start;
            int end;
            double distance;
        };

        /*
        Node nested class inside the RoadNetwork, stores the x_ and y_ coordinates
        Each node's id, and the number of adjacent nodes that this node has
        Also stores a vector of Edges that this node has. 
        */
        class Node {
            public:
            Node(int id, double x, double y) {
                NodeID_ = id;
                x_ = x;
                y_ = y;
                adj = 0;
            }
            int NodeID_;
            double x_;
            double y_;
            int adj;
            vector<Edge> adjLists;//adjacency list
        };

        /*
        @param id, the node id of a node
        @param x, the x coordinate of the node
        @param y, the y coordinate of the node
        addNodes creates a new Node of a pointer and add the Node to the Nodelist_
        */
        void addNode(int id, double x, double y);

        /*
        Draws out the nodes and the edges of the RoadNetwork to a PNG image
        */
        void viewGraph(string filename);

        /*
        Returns the number of edges of a RoadNetwork object
        */
        int EdgeNumber();

        /*
        Returns the number of nodes of a RoadNetwork object
        */
        int NodeNumber();

        /*
        Returns the private list Nodelist_ For testing purposes
        */
        vector<Node*> getNodeList() { return Nodelist_; }

        /*
        Returns the private variable x_ For testing purposes
        */
        double getX() { return x_; }

        /*
        Returns the private variable y_ For testing purposes
        */
        double getY() { return y_; }


        /* 
        add edge to the adjacency list
        */
        void addEdge(int start, int end, double distance);

        /*
        @param start, the starting node (first node)
        @param end, the ending node (second node)
        shortestPath find the distances between the start node and the end node.
        Returns the path consist of node id as vector<int>
        */
        vector<int> shortestPath(int start, int end);

        /*
        Finding the nodes that are strongly connected
        add the strongly connected nodes into a vector at the same index
        Returns the strongly connected components as a 2D-vector with the nodeID as int
        */
        vector<vector<int>> stronglyConnected();

    private:
        //The nodes being added to the 'list', we chose to use a vector structure to store the nodes as pointers
        //with the index being the nodeID. 
        vector<Node*> Nodelist_;
        //number of edges
        int edge;
        //x_ and y_ stores the largest coordinate
        double x_; 
        double y_;

        //helper function to find which nodes are connected, used for strongly connected component function
        void helper(vector<bool>& visited, int i, vector<int>& vect);
};
