#include "../cs225/catch/catch.hpp"
#include "../road_network.h"

#include <vector>

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

