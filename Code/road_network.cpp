#include "road_network.h"
#include<iostream>
#include <queue>
using namespace std;
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
             Nodelist_[start]->adj++;
        }
    }
}
 double RoadNetwork::shortestPath(int start, int end){
     double dist = 0;
     if (start == end){
         return 0;
     } 
     int size = Nodelist_.size(); //size of the graph
     vector<double> distance = vector<double>(size);
     for (auto a: distance) {
         a = INT_MAX;
     }

     return dist;
 }
 vector<vector<int>> RoadNetwork::stronglyConnected(){
     //TODO: find the strongly connected components
     vector<vector<int>> vect;
     return vect;
 }
void RoadNetwork::viewGraph(){
      for (auto a: Nodelist_){
          cout<<a->NodeID_<<"-->"<<endl;
          for (auto b: a->adjLists){
               cout<<b.end<<endl;
          }
      }
}

