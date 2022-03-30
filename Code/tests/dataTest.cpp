#include "data_correction.h"
#include <catch.hpp>

TEST_CASE("files successfully loaded, check for correct format", "nodeData()") {
    map<int, Coordinate> test = nodeData("Code/Data/NodeData.txt");
    REQUIRE(test.size() >= 0);

    SECTION("coordinates are all positive") {
        bool tf = true;
        for (unsigned i = 0; i < test.size(); i++) {
            if (test[i].x < 0 || test[i].y < 0) {
                tf = false;
                break;
            }
        }
        REQUIRE(tf == true);
    }

    SECTION("nodeID are all positive") {
        bool tf = true;
        for(auto it = test.begin(); it != test.end(); ++it) {
            if (it->first < 0) {
                tf = false;
                break;
            }
        }
        REQUIRE(tf == true);
    }
}