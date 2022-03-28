#pragma once
#include <map>
#include <iostream>
using namespace std;

struct Coordinate{
    double x;
    double y;
};
/**
The function takes input of the filename of the Node data file
The file has mutliple lines of the following format: NodeID, x coordinate, y coordinate
In this function, we will take the input, read the input, and store the correct input in a map<NodeID, Coordinate>
If the Node ID is negative or the coordinates are negative, the value would be excluded.
If they are mutiple copies of 1 Node ID, only 1 line would be stored.
**/

map<int, Coordinate> nodeData(string filename);
