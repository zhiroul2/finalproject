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

map<int, Coordinate> edgeData(string filename){
    map<int, Coordinate> vect;
    ifstream myfile;
    string line;
    myfile.open(filename);
    if(!myfile.is_open()) {
      perror("Error open");
      exit(EXIT_FAILURE);
   }
   int id; int x; int y; double z;
    while(myfile >> id >> x >> y >> z) {
        if (id >= 0 && x >= 0 && y >= 0 && z >= 0){
            Coordinate a;
            a.x = x;
            a.y = y;
            a.z = z;
            vect[id] = a;
        }
    }
    return vect;
}
