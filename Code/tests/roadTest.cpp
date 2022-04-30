/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "../cs225/catch/catch.hpp"
#include "../road_network.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

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
        RoadNetwork::Node * node = new RoadNetwork::Node(0, 1, 1);
        expected.push_back(node);
        RoadNetwork::Node * node2 = new RoadNetwork::Node(1, 2, 2);
        expected.push_back(node2);
        RoadNetwork::Node * node1 = new RoadNetwork::Node(2, 3, 3);
        expected.push_back(node1);
        //The value after resizing
        REQUIRE(network.getNodeList().size() == 7);
        REQUIRE(expected.at(0)->NodeID_ == network.getNodeList().at(0)->NodeID_);
        REQUIRE(expected.at(1)->NodeID_ == network.getNodeList().at(1)->NodeID_);
    }
}

TEST_CASE("Check if edges are successfully added to the RoadNetwork class", "[addEdge()]") {

    SECTION("Invalid Edge not added, there cannot exist an edge between the node itself") {
        RoadNetwork network;
        network.addNode(1, 2, 3);
        REQUIRE_THROWS(network.addEdge(1, 1, 3));
    }

    SECTION("Edge successfully added to the Node") {
        RoadNetwork network;
        network.addNode(1, 2, 2);
        network.addNode(2, 4, 4);
        network.addNode(3, 6, 6);
        network.addNode(4, 8, 8);
        network.addEdge(2, 3, 5);
        RoadNetwork::Edge expected = RoadNetwork::Edge(2, 3, 5);
        std::vector<RoadNetwork::Node*> data = network.getNodeList();
        for (size_t i = 1; i < 4; i++) {
            if (data[i]->NodeID_ == 2) {
                REQUIRE(data[i]->adj == 1);
                REQUIRE(data[i]->adjLists[0].distance == expected.distance);
                REQUIRE(data[i]->adjLists[0].start == expected.start);
                REQUIRE(data[i]->adjLists[0].end == expected.end);
            }
        }
    }

    SECTION("Two Edges successfully added to different Nodes") {
        RoadNetwork network;
        network.addNode(0, 0, 0);
        network.addNode(1, 2, 2);
        network.addNode(2, 4, 4);
        network.addNode(3, 6, 6);
        network.addNode(4, 8, 8);
        network.addEdge(3, 4, 5);
        network.addEdge(0, 2, 1);
        RoadNetwork::Edge expected = RoadNetwork::Edge(3, 4, 5);
        RoadNetwork::Edge expected1 = RoadNetwork::Edge(0, 2, 1);
        std::vector<RoadNetwork::Node*> data = network.getNodeList();
        for (size_t i = 0; i < 4; i++) {
            if (data[i]->NodeID_ == 3) {
                REQUIRE(data[i]->adj == 1);
                REQUIRE(data[i]->adjLists[0].distance == expected.distance);
                REQUIRE(data[i]->adjLists[0].start == expected.start);
                REQUIRE(data[i]->adjLists[0].end == expected.end);
            }
            if (data[i]->NodeID_ == 0) {
                REQUIRE(data[i]->adj == 1);
                REQUIRE(data[i]->adjLists[0].distance == expected1.distance);
                REQUIRE(data[i]->adjLists[0].start == expected1.start);
                REQUIRE(data[i]->adjLists[0].end == expected1.end);
            }
        }
    }

    SECTION("Two Edges successfully added to the same node") {
        RoadNetwork network;
        network.addNode(0, 0, 0);
        network.addNode(1, 2, 2);
        network.addNode(2, 4, 4);
        network.addNode(3, 6, 6);
        network.addNode(4, 8, 8);
        network.addEdge(0, 4, 5);
        network.addEdge(0, 2, 1);
        RoadNetwork::Edge expected = RoadNetwork::Edge(0, 4, 5);
        RoadNetwork::Edge expected1 = RoadNetwork::Edge(0, 2, 1);
        std::vector<RoadNetwork::Node*> data = network.getNodeList();
        REQUIRE(data[0]->adj == 2);
        REQUIRE(data[0]->adjLists[0].distance == expected.distance);
        REQUIRE(data[0]->adjLists[0].start == expected.start);
        REQUIRE(data[0]->adjLists[0].end == expected.end);
        REQUIRE(data[0]->adjLists[1].distance == expected1.distance);
        REQUIRE(data[0]->adjLists[1].start == expected1.start);
        REQUIRE(data[0]->adjLists[1].end == expected1.end);
    }
}
 
double calculate_dist(double ax, double ay, double bx, double by) {
    return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}

TEST_CASE("Edge successfully added to the RoadNetwork class", "[addEdge()]") {
    RoadNetwork graph;
    vector <RoadNetwork::Edge> edges;
    graph.addNode(1, 0, 0); //based on the situation that addNode test is passed
    graph.addNode(2, 1, 1);
    graph.addNode(3, 2, 2);
    graph.addNode(4, 10000, 11000);
    SECTION("first edge successfully added to the nodelist->adjLists"){
        edges.push_back(RoadNetwork::Edge(1, 2, sqrt(2)));
        graph.addEdge(1, 2, sqrt(2));
        //cout<<graph.getNodeList().at(1)->NodeID_<<endl;
        REQUIRE(graph.getNodeList().at(1)->adjLists.front().start == edges.front().start);
        REQUIRE(graph.getNodeList().at(1)->adjLists.front().end == edges.front().end);
        REQUIRE(graph.getNodeList().at(1)->adjLists.front().distance == edges.front().distance);
        REQUIRE(graph.getNodeList().at(1)->adjLists.size() == 1);
    }
    SECTION("edges are successfully added"){
        edges.push_back(RoadNetwork::Edge(1, 2, sqrt(2)));
        edges.push_back(RoadNetwork::Edge(1, 3, 2*sqrt(2)));
        edges.push_back(RoadNetwork::Edge(1, 4, calculate_dist(0, 0, 10000, 11000)));
        edges.push_back(RoadNetwork::Edge(2, 3, calculate_dist(1, 1, 10000, 11000)));
        graph.addEdge(1, 2, sqrt(2));
        graph.addEdge(1, 3, 2*sqrt(2));
        graph.addEdge(1, 4, calculate_dist(0, 0, 10000, 11000));
        graph.addEdge(2, 3, calculate_dist(1, 1, 10000, 11000));
        
        REQUIRE(graph.getNodeList().at(1)->adjLists.at(1).start == edges.at(1).start);
        REQUIRE(graph.getNodeList().at(1)->adjLists.at(1).end == edges.at(1).end);
        REQUIRE(graph.getNodeList().at(1)->adjLists.at(1).distance == edges.at(1).distance);
        
        REQUIRE(graph.getNodeList().at(1)->adjLists.at(2).start == edges.at(2).start);
        REQUIRE(graph.getNodeList().at(1)->adjLists.at(2).end == edges.at(2).end);
        REQUIRE(graph.getNodeList().at(1)->adjLists.at(2).distance == edges.at(2).distance);
        REQUIRE(graph.getNodeList().at(1)->adjLists.size() == 3);

        REQUIRE(graph.getNodeList().at(2)->adjLists.front().start == edges.at(3).start);
        REQUIRE(graph.getNodeList().at(2)->adjLists.front().end == edges.at(3).end);
        REQUIRE(graph.getNodeList().at(2)->adjLists.front().distance == edges.at(3).distance);
        REQUIRE(graph.getNodeList().at(2)->adjLists.size() == 1);
    }
}

TEST_CASE("reverse direction doesn't work if there exists only one direction from one node to another", "[shortestPath()]"){
    RoadNetwork test_graph = RoadNetwork();
    test_graph.addNode(1, 1, 2);
    test_graph.addNode(2, 1, 5);
    test_graph.addNode(3, 1, 8);
    test_graph.addEdge(1, 2, 3);
    test_graph.addEdge(2, 3, 3);
    //the path can only go from node 1 to node 3, because there is only one direction
    //if it goes from node 3 to 1, it will produce an empty vector.
    vector <int> test_path = test_graph.shortestPath(3, 1);
    vector <int> actual; //actual path doesn't have any nodes inside, empty vector;
    REQUIRE(test_path == actual);

}

TEST_CASE("Correctly find the shortest path of two nodes SIMPLE", "[shortestPath()]") {
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

TEST_CASE("correctly find the shortest path of two nodes in graph_1 (both directions works)", "[shortestPath()]") {
    RoadNetwork test_graph = RoadNetwork();
    //Add Node
    test_graph.addNode(1, 0, 3);
    test_graph.addNode(2, 4, 0);
    test_graph.addNode(3, 2, 5);
    test_graph.addNode(4, 6, 3);
    test_graph.addNode(5, 10, 3);
    test_graph.addNode(6, 8, 1);
    test_graph.addNode(7, 15, 6.5);
    test_graph.addNode(8, 0, 0);
    //Add Edge
    test_graph.addEdge(1, 2, 4);
    test_graph.addEdge(2, 1, 4);
    test_graph.addEdge(1, 3, 2);
    test_graph.addEdge(3, 1, 2);
    test_graph.addEdge(1, 4, 5);
    test_graph.addEdge(4, 1, 5);
    test_graph.addEdge(1, 8, 2);
    test_graph.addEdge(8, 1, 2);
    test_graph.addEdge(8, 2, 5);
    test_graph.addEdge(2, 8, 5);
    test_graph.addEdge(3, 5, 7);
    test_graph.addEdge(5, 3, 7);
    test_graph.addEdge(3, 4, 2);
    test_graph.addEdge(4, 3, 2);
    test_graph.addEdge(4, 5, 4);
    test_graph.addEdge(5, 4, 4);
    test_graph.addEdge(4, 6, 3);
    test_graph.addEdge(6, 4, 3);
    test_graph.addEdge(2, 6, 4);
    test_graph.addEdge(6, 2, 4);
    test_graph.addEdge(5, 6, 2);
    test_graph.addEdge(6, 5, 2);
    test_graph.addEdge(5, 7, 5);
    test_graph.addEdge(7, 5, 5);
    test_graph.addEdge(6, 7, 7);
    test_graph.addEdge(7, 6, 7);
    SECTION("find the shortest path graph_1"){
        vector <int> test_path = test_graph.shortestPath(2, 7);
        vector <int> actual = {2, 6, 7};
        REQUIRE(test_path == actual);
        test_path = test_graph.shortestPath(1, 6);
        actual = {1, 3, 4, 6};
        REQUIRE(test_path == actual);
    }
    SECTION("the shortest path function produce the same route from node a to b and from b to a, but reversed order"){
        vector <int> test_path = test_graph.shortestPath(8, 7);
        vector <int> reverse_test = test_graph.shortestPath(7, 8);
        reverse (reverse_test.begin(), reverse_test.end());
        REQUIRE(reverse_test == test_path);
    }
    
}

TEST_CASE("correctly find the shortest path when disconnected", "[shortestPath()]") {
     RoadNetwork test_graph = RoadNetwork();
    test_graph.addNode(1, 2, 2);
    test_graph.addNode(2, 4, 4);
    test_graph.addNode(3, 6, 6);
    vector <int> test_path = test_graph.shortestPath(1, 3);
    REQUIRE(test_path.size() == 0);
}

TEST_CASE("Correctly find the shortest path when multiple edges involved", "[shortestPath()]") {
     RoadNetwork test_graph = RoadNetwork();
    vector <int> actual_path = {1, 2, 5};
    test_graph.addNode(1, 2, 2);
    test_graph.addNode(2, 4, 4);
    test_graph.addNode(3, 6, 6);
    test_graph.addNode(4, 8, 8);
    test_graph.addNode(5, 10, 10);
    test_graph.addEdge(1, 5, 10);
    test_graph.addEdge(1, 2, 10);
    test_graph.addEdge(1, 2, 0.2);
    test_graph.addEdge(2, 5, 10);
    test_graph.addEdge(2, 5, 0.3);
    vector <int> test_path = test_graph.shortestPath(1, 5);
    REQUIRE(test_path == actual_path);
}

TEST_CASE("Strongly connected components when the nodes are disconnected", "[stronglyConnected()]") {
    RoadNetwork test_graph = RoadNetwork();
    test_graph.addNode(1, 2, 2);
    test_graph.addNode(2, 4, 4);
    test_graph.addNode(3, 6, 6);
    vector<vector<int>> connected = test_graph.stronglyConnected();
    REQUIRE(connected.size() == 3);
}

TEST_CASE("Strongly connected components when there exist 1 edge", "[stronglyConnected()]") {
    RoadNetwork test_graph = RoadNetwork();
    test_graph.addNode(1, 2, 2);
    test_graph.addNode(2, 4, 4);
    test_graph.addNode(100, 6, 6);
    test_graph.addEdge(1, 2, 10);
    vector<vector<int>> connected = test_graph.stronglyConnected();
    REQUIRE(connected.size() == 2);
}

TEST_CASE("Strongly connected components forming a circle aka one connected component", "[stronglyConnected()]") {
    RoadNetwork test_graph = RoadNetwork();
    test_graph.addNode(1, 2, 2);
    test_graph.addNode(2, 4, 4);
    test_graph.addNode(100, 6, 6);
    test_graph.addEdge(1, 2, 10);
    test_graph.addEdge(2, 100, 10);
    test_graph.addEdge(100, 1, 10);
    vector<vector<int>> connected = test_graph.stronglyConnected();
    REQUIRE(connected.size() == 1);
}

TEST_CASE("Strongly connected components correctly identifies the components", "[stronglyConnected()]") {
    RoadNetwork network;
    //Forming a circle
    network.addNode(0, 0, 0);
    network.addNode(1, 2, 0);
    network.addNode(2, 2, 3);
    network.addNode(3, 3, 2);
    network.addNode(4, 3, 0);
    //Adding the edges to form the circle
    network.addEdge(0, 1, 2);
    network.addEdge(1, 2, 2);
    network.addEdge(2, 3, 2);
    network.addEdge(3, 4, 2);
    network.addEdge(4, 0, 4);
    //Adding an edge to a circle
    network.addNode(5, 6, 0);
    network.addEdge(4, 5, 2);
    //Successfully identifies that as 1 connected component
    std::vector<std::vector<int>> components = network.stronglyConnected();
    std::vector<int> expected = {0, 1, 2, 3, 4, 5};
    REQUIRE(components.size() == 1);
    REQUIRE(components[0].size() == 6);
    for (size_t i = 0; i < components[0].size(); i++) {
        REQUIRE(expected[i] == components[0][i]);
    }
}

TEST_CASE("Strongly connected components identifies two or more connected components", "[stronglyConnected()]") {
    RoadNetwork network;
    //one connected component of size 2
    network.addNode(0, 1, 0); network.addNode(1, 1, 1);
    network.addEdge(0, 1, 1);
    //Second connected component of size 3
    network.addNode(2, 2, 0); network.addNode(3, 2, 1); network.addNode(4, 2, 3);
    network.addEdge(2, 3, 1);
    network.addEdge(3, 4, 2);
    //Third connected component of size 6
    network.addNode(5, 3, 0); network.addNode(6, 3, 1); network.addNode(7, 3, 2); 
    network.addNode(8, 5, 2); network.addNode(9, 7, 0); network.addNode(10, 4, 0); 
    network.addEdge(5, 6, 1);
    network.addEdge(6, 7, 1);
    network.addEdge(7, 8, 3);
    network.addEdge(8, 9, 3);
    network.addEdge(9, 10, 3);
    network.addEdge(10, 5, 1);
    //Checking if the function successfully performs identifying these components
    std::vector<std::vector<int>> components = network.stronglyConnected();
    std::vector<int> one = {0, 1};
    std::vector<int> two = {2, 3, 4};
    std::vector<int> three = {5, 6, 7, 8, 9, 10};
    REQUIRE(components.size() == 3);
    REQUIRE(components[0].size() == one.size());
    REQUIRE(components[1].size() == two.size());
    REQUIRE(components[2].size() == three.size());
    for (size_t i = 0; i < components.size(); i++) {
        for (size_t j = 0; j < components[i].size(); j++) {
            if (i == 0) {
                REQUIRE(components[i][j] == one[j]);
            } else if (i == 1) {
                REQUIRE(components[i][j] == two[j]);
            } else if (i == 2) {
                REQUIRE(components[i][j] == three[j]);
            }
        }
    }
}

TEST_CASE("strongly connected components correclty identifies a strongly connected when several edges connects", "[stronglyConnected()]") {
    RoadNetwork network;
    //Creating a cylic graph
    network.addNode(0, 0, 2); network.addNode(1, 2, 3); network.addNode(2, 3, 2); 
    network.addNode(3, 2, 0); network.addNode(4, 4, 3); network.addNode(5, 5, 2); network.addNode(6, 4, 0);
    network.addEdge(0, 1, 1);
    network.addEdge(1, 2, 1);
    network.addEdge(2, 3, 1);
    network.addEdge(3, 0, 1);
    network.addEdge(4, 1, 1);
    network.addEdge(5, 2, 1);
    network.addEdge(6, 3, 1);
    network.addEdge(4, 5, 1);
    network.addEdge(5, 6, 1);
    //Checking if the function identifies this as connected components
    std::vector<std::vector<int>> components = network.stronglyConnected();
    REQUIRE(components.size() == 2);
    std::vector<int> one = {0, 1, 2, 3};
    std::vector<int> two = {4, 5, 6};
    REQUIRE(components[0].size() == one.size());
    REQUIRE(components[1].size() == two.size());
    for (size_t i = 0; i < components.size(); i++) {
        for (size_t j = 0; j < components[i].size(); j++) {
            if (i == 0) {
                REQUIRE(components[i][j] == one[j]);
            } else if (i == 1) {
                REQUIRE(components[i][j] == two[j]);
            }
        }
    }
}

TEST_CASE("strongly connected components correclty identifies the connected components with one edge indirectly connected", "[stronglyConnected()]") {
    RoadNetwork network;
    //Creating a cycle with four connected nodes
    network.addNode(0, 0, 3); network.addNode(1, 1, 4); network.addNode(2, 2, 3); network.addNode(3, 1, 0);
    network.addEdge(0, 1, 1);
    network.addEdge(1, 2, 1);
    network.addEdge(2, 3, 1);
    network.addEdge(3, 4, 1);
    //Adding the node that is connected with one of the node within the cycle
    network.addNode(4, 3, 4);
    network.addEdge(4, 2, 2);
    //Adding the node that is connected to the last node
    network.addNode(5, 4, 5);
    network.addEdge(4, 5, 2);
    //Checking if they the cycle is connected
    //The last two nodes are not
    std::vector<std::vector<int>> components = network.stronglyConnected();
    REQUIRE(components.size() == 1);
}


/////////////////////////////////////////////////////////////////////////////////////////////
//                               End of Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////