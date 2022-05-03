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
    RoadNetwork test = RoadNetwork();
    test.addNode(0, 20, 20);
    test.addNode(1, 30, 30);
    test.addNode(3, 70, 80);
    test.addNode(2, 20, 20);
    test.addEdge(0, 3, 20);
    test.addEdge(1, 2, 60);
    //cout<<graph.EdgeNumber()<<endl; 
    for (auto a: test.shortestPath(0, 2)){
        cout<<a<<endl;
    }
    test.viewGraph("simple.png");
    //cout<<graph.stronglyConnected().size()<<endl;
    graph.viewGraph("graphImage.png");
    //cout<<graph.stronglyConnected().size()<<endl;// make sure that it's inserted
    return 1;
}
