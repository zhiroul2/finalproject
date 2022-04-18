#include "road_network.h"
#include<iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include "cs225/PNG.h"

using namespace std;

//using namespace cs225;

typedef pair<int,int> myPair;

RoadNetwork::~RoadNetwork() {
    clear();
}

void RoadNetwork::clear() {
    for (size_t i = 0; i < Nodelist_.size(); i++) {
        if (Nodelist_[i] != NULL) {
            delete Nodelist_[i];
            Nodelist_[i] = NULL;
        }
    }
}

void RoadNetwork::addNode(int id, double x, double y){
    //if the vector is empty, create a empty vector allocating space for the vector
    if (Nodelist_.empty()) {
        Nodelist_ = vector<Node*>(2*id + 1);
    }
    //Due to the reality of the node coordinate, to better draw the nodes out, we resize the coordinate to 10 times smaller
    //Updating the largest x_ coordinate found in the data
    if (x/10 > x_) {
        x_ = x/10;
    }
    //Updating the largest y_ coordinate found in the data
    if (y/10 > y_) {
        y_ = y/10;
    }
    //Create the node that will be added to the nodelist
    Node* a = new Node(id, x/10, y/10);
    //Adding the node to the nodelist
    Nodelist_.insert(Nodelist_.begin() + id, a);
}

void RoadNetwork::addEdge(int start, int end, double distance) {
    // Cheking the starting point and the ending points are valid
    if (0 <= start < int(Nodelist_.size()) && 0 <= end < int(Nodelist_.size())){
        //Making sure that the node at the index start and index end is not a nullptr
        if (Nodelist_[start] != NULL && Nodelist_[end] != NULL) {
            //adding the possible neighbors (in terms of its starting point and ending point and distance)
            //to the adjLists (which is tracted by Node class inside RoadNetwork)
            Nodelist_[start]->adjLists.push_back(Edge(start, end, distance));
            //adding the number of possible neighbors
            Nodelist_[start]->adj++;
            //adding the number of edges, the connections between nodes
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

vector<int> RoadNetwork::shortestPath(int start, int end) {
    vector<int> path;
    if (start == end){
         return path;
     }
     int size = Nodelist_.size(); //size of the graph
     if (!(0 <= start < size) or !(0 <= end < size)){
         path.push_back(-1000); // No node exist, warning signal
     }
     vector<double> distance = vector<double>(size);
     vector<int> prev = vector<int>(size);
     for (int i = 0; i < size; i++){
         distance[i] = 1000000007;
     }
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(start, 0));
    distance[start] = 0;
    while(!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        vector<Edge> n = Nodelist_[u]->adjLists;
        for(auto it: n){
            int v = it.end;
            int weight = it.distance;
            if(distance[v] > distance[u] + it.distance) {
                distance[v] = distance[u] + it.distance;
                 pq.push(make_pair(v, distance[v]));
                 prev[v] = u;
            }
        }
    }
    if (distance[end] == 0 or distance[end] == 1000000007){
        return path; // when there's no path bettween the two nodes
    }
    int i = end;
    while(prev[i] != start){
        cout<<prev[i]<<endl;
        path.push_back(prev[i]);
        i = prev[i];
    }
    return path;
 }

void RoadNetwork::helper(vector<bool>& visited, int i , vector<int>& c){
    c.push_back(i);
    visited[i] = true;
    for (auto  a: Nodelist_[i]->adjLists){
        if (!visited[a.end]){
            if (a.end < int(Nodelist_.size())){
                helper(visited, a.end, c);
            }
        }
    }
}

vector<vector<int>> RoadNetwork::stronglyConnected(){
     vector<vector<int>> vect;
     int size = Nodelist_.size();
     vector<bool> visited = vector<bool>(size);
     for (int i = 0; i < size; i++){
      visited[i] = false;
     }
     for (int i = 0; i < size; i++){
         if (!visited[i] and Nodelist_[i] != NULL){
             vector<int> c;
             helper(visited, i, c);
             vect.push_back(c);
             visited[i] = true;
         }
     }
     return vect;
}

void RoadNetwork::viewGraph(){
    unsigned height = int(y_) + 1;
    unsigned width = int(x_) + 1;
    cs225::PNG* canvas = new cs225::PNG(width, height); 
    //canvas->getPixel(2, 2).l = 0;//Our current dataset is too big, just for show
    for (auto a : Nodelist_){
        if (a != NULL){
            canvas->getPixel(unsigned (a->x_), unsigned (a->y_)).l = 0.2;
            canvas->getPixel(unsigned (a->x_), unsigned (a->y_)).s = 0.2;
            canvas->getPixel(unsigned (a->x_), unsigned (a->y_)).h = 180;
        }
    }
    //TODO: blacken the path:Most direct route
    canvas->writeToFile("graphImage"+ string(".png"));
}

