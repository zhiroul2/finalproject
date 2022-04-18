#include "../road_network.h"
#include "./catch/catch.hpp"
#include <vector>

TEST_CASE("Nodes successfully added to the RoadNetwork class", "[addNode()]") {
    vector<Node*> expected;
    RoadNetwork network;

    SECTION("first node successfully added to the nodelist") {
        Node * node = new Node(0, 1, 1);
        expected.push_back(node);
        network.x_ = 0; network.y_ = 0;
        //The data of real roadnetwork are fairly large, so when testing, we chose numbers
        //that is closer to the real data and test for the correctness of the funciton.
        network.addNode(0, 10, 10);
        REQUIRE(expected.size() == network.Nodelist_.size());
        REQUIRE(expected.at(0)->NodeID_ == network.Nodelist_.at(0)->NodeID_);
        REQUIRE(expected.at(0)->x_ == network.Nodelist_.at(0)->x_);
        REQUIRE(expected.at(0)->y_ == network.Nodelist_.at(0)->y_);
        //deleting the nodes inside the vectors for further testing
        for (size_t i = 0; i < expected.size(); i++) {
            if (expected[i] != NULL) {
                delete expected[i];
                expected[i] = NULL;
                delete network.Nodelist_[i];
                network.Nodelist_[i] = NULL;
            }
        }
    }

    SECTION("node is successfully inserted at the correct index based on its nodeID, inserting in random order") {
        Node * node = new Node(0, 1, 1);
        expected.push_back(node);
        Node * node1 = new Node(1, 2, 2);
        expected.push_back(node1);
        Node * node2 = new Node(2, 3, 3);
        expected.push_back(node2);
        network.x_ = 0; network.y_ = 0;
        network.addNode(0, 10, 10);
        network.addNode(2, 30, 30);
        REQUIRE(network.Nodelist_.size() == 2);
        //adding a node in between nodes with id 0 and 2 to check if it is being added to the correct
        //index of 1
        network.addNode(1, 20, 20);
        REQUIRE(expected.size() == network.Nodelist_.size());
        REQUIRE(expected.at(1)->NodeID_ == network.Nodelist_.at(1)->NodeID_);
        REQUIRE(expected.at(1)->x_ == network.Nodelist_.at(1)->x_);
        REQUIRE(expected.at(1)->y_ == network.Nodelist_.at(1)->y_);
    }
}

TEST_CASE("Edges successfully added to the RoadNetwork class", "[addEdge()]") {
    RoadNetwork network;
    nodes.edge = 0;
    
}