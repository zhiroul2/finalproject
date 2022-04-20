#include "../cs225/catch/catch.hpp"
#include "../data_correction.h"

/*
TEST_CASE("files successfully loaded, check for all positive data", "[nodeData()]") {
    map<int, Coordinate> test = nodeData("Code/Data/DataCorrection.txt");
    REQUIRE(test.size() == 4);

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
        for (auto it = test.begin(); it != test.end(); ++it) {
            if (it->first < 0) {
                tf = false;
                break;
            }
        }
        REQUIRE(tf == true);
    }
}

TEST_CASE("data processed should end up with no duplicates", "[nodeData()]") {
    map<int, Coordinate> test = nodeData("Code/Data/DuplicateData.txt");
    REQUIRE(test.size() == 5);

    SECTION("nodeID should change accordingling to accommodate for the duplicates") {
        int previous = 0;
        for (auto it = test.begin(); it != test.end(); ++it) {
            REQUIRE(it->first == previous + 1);
            previous++;
        }
    }
}

TEST_CASE("files successfully loaded, check for all positive data for edge", "[edgeData()]") {
    map<int, EdgeData> test = edgeData("Code/Data/DataCorrection.txt");
    REQUIRE(test.size() == 4);
    
    SECTION("start nodes, end nodes, and distances are all positive") {
        bool tf = true;
        for (unsigned i = 0; i < test.size(); i++){
            if (test[i].startNode < 0 || test[i].endNode < 0 || test[i].distance >= 0) {
                tf = false;
                break;
            }
        }
        REQUIRE(tf == true);
    }
    
    SECTION("edgeID are all positive") {
        bool tf = true;
        for (auto it = test.begin(); it != test.end(); ++it) {
            if (it->first < 0) {
                tf = false;
                break;
            }
        }
        REQUIRE(tf == true);
    }
}
*/