#include "road_network.h"
#include<iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
#include "cs225/PNG.h"

using namespace std;

//using namespace cs225;

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
    //if the id is out of bounds, resize vector
    if (id > (int) Nodelist_.size()) {
        Nodelist_.resize(2*id + 1);
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
    Node* node = new Node(id, x/10, y/10);
    //Adding the node to the nodelist
    Nodelist_.insert(Nodelist_.begin() + id, node);
}

void RoadNetwork::addEdge(int start, int end, double distance) {
    // Cheking the starting point and the ending points are valid
    if (0 <= start < int(Nodelist_.size()) && 0 <= end < int(Nodelist_.size()) && start != end) {
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
    } else {
        throw std::invalid_argument("the edge attempting to add is invalid");
    }
}

int RoadNetwork::EdgeNumber() {
    return edge;
}

int RoadNetwork::NodeNumber() {
    return Nodelist_.size();
}

vector<int> RoadNetwork::shortestPath(int start, int end) {
    vector<int> path;
    //If the two nodes are the same
    if (start == end){
        return path;
    }
    //size of the graph
    int size = Nodelist_.size();
    //Check if the node exist
    if (!(0 <= start < size) or !(0 <= end < size)){
        //No node exist, warning signal
        path.push_back(-1000);
    }
    //Allocate space for potential edges
    vector<double> distance = vector<double>(size);
    //Allocate space for previous node
    vector<int> prev = vector<int>(size);
    //Setting the default distance to 1000000007
    for (int i = 0; i < size; i++){
        distance[i] = 1000000007;
    }
    //Creating a priority queue to find the shorest path, a vector to store pairs of nodes, greater for comparisons
    //BFS
    priority_queue<int, vector<int>, greater<int>> pq;
    //Initialize the starting point
    vector<bool> visited(size, false);
    pq.push(start);
    distance[start] = 0;
    while(!pq.empty()) {
        int fir_node = pq.top();
        visited[fir_node] = true;
        pq.pop();
        vector<Edge> adj_edges = Nodelist_[fir_node]->adjLists;
        for(auto it: adj_edges){
            int sec_node = it.end;
            int weight = it.distance;
            if(distance[sec_node] > distance[fir_node] + it.distance) {
                if (!visited[sec_node]){
                    pq.push(sec_node);
                }
                distance[sec_node] = distance[fir_node] + it.distance;
                prev[sec_node] = fir_node;
            }
        }
    }
    if (distance[end] == 0 or distance[end] == 1000000007){
        return path; // when there's no path bettween the two nodes
    }
    int e = end;
    path.push_back(start);
    vector <int> temp;
    while (prev[end] != start){
        temp.push_back(prev[end]);
        end = prev[end];
    }
    reverse(temp.begin(), temp.end());
    for (unsigned i = 0; i < temp.size(); i++){
        path.push_back(temp[i]);
    }
    path.push_back(e);
    return path;

 }

void RoadNetwork::helper(vector<bool>& visited, int i , vector<int>& vect) {
    //The node is always connected to itself
    vect.push_back(i);
    //Marking the node as visited
    visited[i] = true;
    //Looping through its adjList to see which other nodes are connected
    for (auto it : Nodelist_[i]->adjLists){
        if (!visited[it.end]){ 
            if (it.end < int(Nodelist_.size())){
                helper(visited, it.end, vect);
            }
        }
    }
}

vector<vector<int>> RoadNetwork::stronglyConnected() {
    vector<vector<int>> vect;
    //Getting the number of nodes stored in road network object
    int size = Nodelist_.size();
    //Initialize the visited vector to false
    vector<bool> visited = vector<bool>(size, false);
    for (int i = 0; i < size; i++){
        //If a particular node has not been visited and it does exist
        if (!visited[i] && Nodelist_[i] != NULL) {
            vector<int> temp;
            //Using helper function to find the stronglyConnected component & putting them into a vector
            helper(visited, i, temp);
            //Pushing back the vector that contains the nodes that are strongly connected to each other
            vect.push_back(temp);
            //Marking the node as visited
            visited[i] = true;
        }
    }
    return vect;
}

void RoadNetwork::viewGraph(string filename) {
    unsigned height = int(y_) + 1;
    unsigned width = int(x_) + 1;
    cs225::PNG* canvas = new cs225::PNG(width, height); 
    //Don't change//
    for (auto cur_node : Nodelist_){
        if (cur_node != NULL){
            for (auto a : cur_node->adjLists){
            if (Nodelist_[a.start]->x_ ==  Nodelist_[a.end]->x_){
                double high = max(Nodelist_[a.start]->y_, Nodelist_[a.end]->y_);
                int low = min(Nodelist_[a.start]->y_, Nodelist_[a.end]->y_);
                for (int i = low; i < high; i++){
                     canvas->getPixel(Nodelist_[a.start]->x_, low).l = 0;
                }
            }
            if (Nodelist_[a.start]->x_ < Nodelist_[a.end]->x_){
                int slope = (Nodelist_[a.end]->y_ - Nodelist_[a.start]->y_)/(Nodelist_[a.end]->x_ - Nodelist_[a.start]->x_);
                int count = 0;
                for (int i = int(Nodelist_[a.start]->x_); i < Nodelist_[a.end]->x_; i++){
                     canvas->getPixel(i, Nodelist_[a.start]->y_ + slope*(count)).l = 0;
                     count++;
                }
            } 
            if (Nodelist_[a.start]->x_ > Nodelist_[a.end]->x_ ){
                int slope = 0;
                if ((Nodelist_[a.start]->y_ - Nodelist_[a.end]->y_) > 1){
                   slope = (Nodelist_[a.start]->y_ - Nodelist_[a.end]->y_)/(Nodelist_[a.start]->x_ - Nodelist_[a.end]->x_);
                } 
                int count = 0;
                for (int i = int(Nodelist_[a.end]->x_); i < Nodelist_[a.start]->x_; i++){
                     canvas->getPixel(i, Nodelist_[a.end]->y_ + slope*(count)).l = 0;
                     count++;
                }  
            }
        }
        }
    }
    //Don't change
    
    vector<vector<int>> vect = stronglyConnected();
    int i = 10; double j = 0.1;
    for (auto part: vect){
        for (auto a: part){
            Node* cur_node = Nodelist_[a];
            canvas->getPixel(unsigned (cur_node->x_), unsigned (cur_node->y_)).l = 0.5;
            canvas->getPixel(unsigned (cur_node->x_), unsigned (cur_node->y_)).s = j;
            canvas->getPixel(unsigned (cur_node->x_), unsigned (cur_node->y_)).h = i;
        }
        i += 30;
        j += 0.5;
    }
    
    canvas->writeToFile(filename);
}


