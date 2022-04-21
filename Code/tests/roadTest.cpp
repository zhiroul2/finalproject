#include "../cs225/catch/catch.hpp"
#include "../road_network.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

TEST_CASE("Nodes successfully added to the RoadNetwork class", "[addNode()]") {
    vector<RoadNetwork::Node*> expected;
    RoadNetwork network;

    SECTION("first node successfully added to the nodelist") {
        RoadNetwork::Node * node = new RoadNetwork::Node(0, 1, 1);
        expected.push_back(node);
        //The data of real roadnetwork are fairly large, so when testing, we chose numbers
        //that is closer to the real data and test for the correctness of the funciton.
        network.addNode(0, 10, 10);
        REQUIRE(expected.size() == network.getNodeList().size());
        REQUIRE(expected.at(0)->NodeID_ == network.getNodeList().at(0)->NodeID_);
        REQUIRE(expected.at(0)->x_ == network.getNodeList().at(0)->x_);
        REQUIRE(expected.at(0)->y_ == network.getNodeList().at(0)->y_);
        //deleting the nodes inside the vectors for further testing
        network.clear();
        expected.clear();
    }


    SECTION("node is successfully inserted at the correct index based on its nodeID, inserting in random order") {
        network.addNode(0, 10, 10);
        network.addNode(2, 30, 30);
        network.addNode(1, 20, 20);
    }
}


double calculate_dist(double ax, double ay, double bx, double by){
    return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}

TEST_CASE("correctly find the shortest path of two nodes SIMPLE"){
    RoadNetwork test_graph = RoadNetwork();
    test_graph.addNode(1, 2, 2);
    test_graph.addNode(2, 4, 4);
    test_graph.addNode(3, 6, 6);
    test_graph.addNode(4, 8, 8);
    test_graph.addNode(5, 10, 10);
    test_graph.addNode(6, 100, 100);
    test_graph.addNode(7, 2, 100);
    test_graph.addEdge(1, 2, calculate_dist(2,2,4,4));
    test_graph.addEdge(2, 3, calculate_dist(4,4,6,6));
    test_graph.addEdge(3, 4, calculate_dist(6,6,8,8));
    test_graph.addEdge(4, 5, calculate_dist(8,8,10,10));
    test_graph.addEdge(5, 6, calculate_dist(10,10,100,100));
    test_graph.addEdge(1, 7, calculate_dist(2,2,100,100));
    test_graph.addEdge(6, 7, calculate_dist(100,100,2,100));
    vector <int> test_path = test_graph.shortestPath(1, 6);
    vector <int> actual_path;
    for (int i = 1; i < 7; i++){
        actual_path.push_back(i);
    }
    REQUIRE(test_path == actual_path);
}
