#include<iostream>
#include<vector>
#include "data_correction.h"
#include "road_network.h"
using namespace std;

int main() {
    map<int, Coordinate> vect = nodeData("./Data/NodeData.txt");
    map<int, EdgeData> edge = edgeData("./Data/EdgeData.txt");
    RoadNetwork graph = RoadNetwork();
    //graph.shortestPath(1, 0);
    cout<<vect[0].x<<endl;
    //graph.addNode(0, 1.3, 1.3);
    for (auto a: vect) {
        cout<<a.second.x<<endl;
        graph.addNode(a.first, a.second.x, a.second.y);
    }

    return 0;
}