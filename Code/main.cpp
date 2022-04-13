#include<iostream>
#include<vector>
#include "data_correction.h"
#include "road_network.h"

using namespace std;

int main() {
    map<int, Coordinate> vect = nodeData("./Data/NodeData.txt");
    map<int, EdgeData> edge = edgeData("./Data/EdgeData.txt");
    //cout<<(vect.size())<<endl;
    //cout<<edge.size()<<endl;
    //After the data correction, we decided on the adj list implmentation since m << n^2
    RoadNetwork graph = RoadNetwork();
    for (auto a: vect) {
        graph.addNode(a.first, a.second.x, a.second.y);
    }
    for (auto b: edge){
        graph.addEdge(b.second.startNode, b.second.endNode, b.second.distance);
    }
    RoadNetwork test = RoadNetwork();
    cout<<graph.EdgeNumber()<<endl; 
    cout<<graph.stronglyConnected().size()<<endl;// make sure that it's inserted
    return 1;
}