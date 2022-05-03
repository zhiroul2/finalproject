#include<iostream>
#include<vector>
#include "data_correction.h"
#include "road_network.h"

using namespace std;

int main() {
    map<int, Coordinate> vect = nodeData("./Data/NodeData.txt");
    map<int, EdgeData> edge = edgeData("./Data/EdgeData.txt");
    //After the data correction, we decided on the adj list implmentation since m << n^2
    RoadNetwork graph = RoadNetwork();
    for (auto a: vect) {
        graph.addNode(a.first, a.second.x, a.second.y);
    }
    for (auto b: edge){
        graph.addEdge(b.second.startNode, b.second.endNode, b.second.distance);
    }
    cout<<"The node number is "<<graph.NodeNumber() <<endl;
    cout<<"The edge number is "<<graph.EdgeNumber() <<endl;
    cout<< graph.stronglyConnected().size() << endl;
    graph.viewGraph("graphImage.png");
    return 1;
}
