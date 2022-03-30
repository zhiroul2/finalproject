#pragma once
#include <map>
#include <iostream>

using namespace std;

struct Coordinate {
    double x;
    double y;
};

struct EdgeData {
    int startNode;
    int endNode;
    double distance;
};

/*
The function takes input of the filename of the Node data file
The file has mutliple lines of the following format: NodeID, x coordinate, y coordinate
In this function, we will take the input, read the input, and store the correct input in a map<NodeID, Coordinate>
If the Node ID is negative or the coordinates are negative, the value would be excluded.
If there are mutiple copies of 1 Node ID, only 1 line would be stored.
*/
map<int, Coordinate> nodeData(string filename);

/*
This function takes a @param filename and returns a map contains keys of integer as nodeID, 
with it's corresponding values of EdgeData.
The file contains the data in the order of nodeID, the startnode, the endnode, and the distance between the two ndoes.
edgeData completes the task of importing the data and transforming the data into a map specified above.
*/
map<int, EdgeData> edgeData(string filename);
