#include "data_correction.h"
#include<iostream>
#include <vector>
#include<fstream>

using namespace std;
/**
The function takes input of the filename of the Node data file
The file has mutliple lines of the following format: NodeID, x coordinate, y coordinate
In this function, we will take the input, read the input, and store the correct input in a map<NodeID, Coordinate>
If the Node ID is negative or the coordinates are negative, the value would be excluded.
If there are mutiple copies of 1 Node ID, only 1 line would be stored.
**/
map<int, Coordinate> nodeData(string filename) {
    map<int, Coordinate> vect;
    ifstream myfile;
    string line;
    myfile.open(filename);
    if(!myfile.is_open()) {
      perror("Error open");
      exit(EXIT_FAILURE);
   }
   int id; double x; double y;
    while (myfile >> id >> x >> y) {
        if (id >= 0 and x >= 0 and y >= 0){
            Coordinate a;
            a.x = x;
            a.y = y;
            vect[id] = a;
        }
    }
    return vect;
}

map<int, EdgeData> edgeData(string filename){
    map<int, EdgeData> vect;
    ifstream myfile;
    string line;
    myfile.open(filename);
    if(!myfile.is_open()) {
      perror("Error open");
      exit(EXIT_FAILURE);
   }
   int id; int start; int end; double distance;
    while(myfile >> id >> start >> end >> distance) {
        if (id >= 0 && start >= 0 && end >= 0 && distance >= 0){
            EdgeData a;
            a.startNode = start;
            a.endNode = end;
            a.distance = distance;
            vect[id] = a;
        }
    }
    return vect;
}
