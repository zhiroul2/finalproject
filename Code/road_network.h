#pragma once
#include <map>
#include <vector>
#include "stdlib.h"


#include "data_correction.h"

class RoadNetwork {
    public:
        /*
        @param the data contains information about the edgeData
        distance function finds the distances between two connected network nodes and sort them into a vector
        Returns a vector of double (distances) of any two nodes that are connected
        Helper for the shortestPath function
        */
        std::vector<double> distance(std::map<int, EdgeData> data);
        /*
        @param the vector of coordinates of the nodes, the index represents the nodeID
        @param the vector distances between the two nodes
        shortestPath comapres the distances between two nodes and finding the start and end node which has the shortest path
        Returns a pair of int with the first being the start nodeID and the second is the end nodeID
        */
        std::pair<int, int> shortestPath(std::vector<Coordinate> coordinate, std::vector<double> distance);
        
    private:
        //The map containing the nodeID and its coorsponding x and y coordinates of the road networks
        std::map<int, Coordinate> nodeData_;
        //The map map containing the nodeID and its startNode and endNode of the road networks
        std::map<int, EdgeData> edgeData_;
};
