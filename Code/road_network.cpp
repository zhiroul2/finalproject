#include "road_network.h"
#include<iostream>
#include <queue>

using namespace std;
typedef pair<int,int> myPair;
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
             edge++;
        }
    }
}
int RoadNetwork::EdgeNumber(){
    return edge;
}
int RoadNetwork::NodeNumber(){
    return Nodelist_.size();
}
double RoadNetwork::shortestPath(int start, int end){
    if (start == end){
         return 0;
     }
     int size = Nodelist_.size(); //size of the graph
     if (!(0 <= start < size) or !(0 <= end < size)){
         //path.push_back(-1000); // No node exist, warning signal
         return -1000;
     }
     vector<double> distance = vector<double>(size);
     for (int i = 0; i < size; i++){
         distance[i] = 1000000007;
     }
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(start, 0));
    distance[start] = 0;
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        vector<Edge> n = Nodelist_[u]->adjLists;
        for(auto it: n){
            int v = it.end;
            int weight = it.distance;
            if(distance[v] > distance[u] + it.distance) {
                distance[v] = distance[u] + it.distance;
                 pq.push(make_pair(v, distance[v]));
            }
        }
    }
    return distance[end];
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

