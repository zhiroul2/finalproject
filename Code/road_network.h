#pragma once

#include <map>
#include <vector>
#include<string>
#include "cs225/PNG.h"
using namespace std;

class RoadNetwork {
    public:
        RoadNetwork() { Nodelist_ = vector<Node*>(); x_= 0; y_ = 0;}
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
        
        void addNode(int id, double x, double y);
        void viewGraph();
        int EdgeNumber();
        int NodeNumber();
        /* add edge to the adjacency list
        */
        void addEdge(int start, int end, double distance);
        /*
        shortestPath find the distances between the start node and the end node.
        Returns the path consist of node id as vector<int>
        */
        vector<int> shortestPath(int start, int end);
        /*

        */
        vector<vector<int>> stronglyConnected();

    private:
        //nodes
        vector<Node*> Nodelist_;
        int edge; //number of edges
        //x_ and y_ stores the largest coordinate
        double x_; double y_;
        void helper(vector<bool>& visited, int i, vector<int>& c);
};
