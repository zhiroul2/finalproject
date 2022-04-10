#include "road_network.h"
#include<iostream>
void RoadNetwork::addNode(int id, double x, double y){
    if (Nodelist_.empty()) {
         Nodelist_ = vector<Node*>(2*id + 1);
    }
    Node* a = new Node(id, x, y);
    Nodelist_.insert(Nodelist_.begin() + id, a);
}
void RoadNetwork::addEdge(int start, int end, double distance){
    if (0 < start < int(Nodelist_.size())){
        if (Nodelist_[start]){
             Nodelist_[start]->adjLists.push_back(Edge(start, end, distance));
        }
    }
}
 string RoadNetwork::shortestPath(int start, int end){
     if (start == end){
         return "";
     }
     //TODO: Find the shortest path by DFS
     return "";
 }
 vector<vector<int>> RoadNetwork::stronglyConnected(){
     //TODO: find the strongly connected components
     vector<vector<int>> vect;
     return vect;
 }