#pragma once

#include <map>
#include <vector>
#include<string>
using namespace std;

class RoadNetwork {
    public:
        RoadNetwork(){ Nodelist_ = vector<Node*>();}
        class Edge{
            public:
            Edge(int start_, int end_, double distance_){
                start = start_;
                end = end_;
                distance = distance_;
            }
            int start;
            int end;
            double distance;
        };
        class Node{
            public:
            Node(int id, double x, double y){
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

        /* add edge to the adjacency list
        */
        void addEdge(int start, int end, double distance);
        /*
        shortestPath find the distances between the start node and the end node.
        Returns a string consist of the node visted in the path
        */
        double shortestPath(int start, int end);
        /*

        */
        vector<vector<int>> stronglyConnected();
    private:
        //nodes
        vector<Node*> Nodelist_;
        /*
        @para NodeID for the start node
        helper function for shortest path
        */
       

};
