Leading question :

Knowing the power of network analysis, we will represent network as graph structure. The motivation here is to implement actual application that can be useful in networks.

We will be mainly focusing on two leading questions:

First, how to find the shortest path between two nodes, given the coordinates of every node and the distances between every two nodes on the map.
Second, how to find an area that has the most concentrated nodes connections, seperate the disjoint area, and possibility color them in order to distinguish the structure of the graph.

Third, we might consider to store the weighted adjacency matrix to save space in memory and, if we have time, calculate the eigenvector and thus find the most "popular" node, which carries the most traffic and results in security concerns.

In order to solve these two problems, one algorithm is to find the shortest route and distance between two nodes, and another one is to find a group of nodes that has more connections and degrees than other nodes (thus could find some areas that are more concentrated with nodes and edges).

We will use the dataset that contains the information of the x and y coordinates of every eixsted node in a city, the distance between two nodes, the nodeID, and the edgeID. We will be using these information to approach the leading questions raised above.

We will also represent the data in the form of a directed graph, which is a design choice that eliminates confusion when determining the strongly connected component. Thus, we choose to only store the edge (if there exists one) in the start node in addEdge function. We use the structure of adjacency list since this is a directed graph and our n*n is significantly larger than m.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

We answer the question by creating a RoadNetwork class.
We create  RoadNetwork class and store the lists of nodes(Node is an inner class for road_network class to better extract information and provide interface needed) as a vector<Node*>, each node contains an adjacency list as vector<Edge> where edge is also an inner class.
  

in our Node class, we store the int Nodeid, double x_, double y_, vector<edge> adjLists, and in each edge class, it stores int start, int end, double distance.

Since we have no idea what's the order of the user's input of nodes, so we resize the dynamic array of nodes based on the given Nodeid. As a consequence of this type of behavior, there will be NULL in our Nodelist_(Another reason we use Node* instead of Node, we want avoid useless memory allocation on stack).
 
In order to visualize the graph, we store the double x_, double y_ as the maximum value of x coordinate and y coordinate that we encounter during data processing. Since our dataset is on the larger side, we take a factor of 0.1 to our x and y coordinate value to balance the size of our graph. Meanwhile we also track the number of total edges as a class variable to show the general settings of the dataset in our graph.

Algorithm:

Shortest path by Dijkstra’s Algorithm:
  
    Signature:

       /*
        @param start, the starting node (first node)
        @param end, the ending node (second node)
        shortestPath find the distances between the start node and the end node.
        Returns the path consist of node id as vector<int>
        */
  
        vector<int> shortestPath(int start, int end);
  
In this alorithm, we use a priority queue to do the BFS transversal and use two vectors which has the exact same size of the Nodelist_ to keep track of the shortest path.We are not using a min-priority queue, thus the actual runtime is O(|E|log|V|).
  

Test Cases:

  

Strongly Connected Components:
  
    Signature:

       /*
        Finding the nodes that are strongly connected
        add the strongly connected nodes into a vector at the same index
        Returns the strongly connected components as a 2D-vector with the nodeID as int
        */
  
        vector<vector<int>> stronglyConnected();
  
In this alorithm, we use the vector<visited> to avoid infinite loops and track each node.We use DFS transversal on a directed graph.
The worst case is O(V+E) where V = vertices and E = edges.


Test Cases:

1. The first test case for stronglyConnected() is to test if the algorithm properly identidies individual nodes   as not connected is no edges exist between them. The test case successfully showed that three nodes are not connected.

2. The second test case for stronglyConnected() is to test if the algorithm identifies the two nodes that are connected by an edge a strongly connected component and the other node (without any edges linked to it) as the other component. The test case successfully showed that there exist two components.

3. The third test case for stronglyConnected() is to test if the algorithm identifies three nodes as one connected components if there exists a cycle, meaning, the three nodes are connected together by three edges forming a cycle. The test case successfully showed that there is one connected components.

4. The fourth test case for stronglyConnected() is to test if the algorithm identifies an extra node connected to a cycle (formed by 5 nodes) as one connected component. The test case successfully showed that there is one connected components.

5. The fifth test case for stronglyConnected() is to test if the algorithm identifies two nodes connected with one edge between them, three nodes with two edges between them, and a six nodes cycle as three seperate connected components. This is one of the more complex test cases for stronglyConnected(). The test case also made sure that the output of the stronglyConnected() (vector<vector<<int>>) matches the expected vectors. The test case successfully showed that there are three connected components, and the output matches the expected vectors. 


6. The sixth test case for stronglyConnected() is to test if the algorithm identifies a cycle as two connected components. The reason being that our graph structure stores directed edges, so the fourth, fifth, and the sixth node will be counted as another components rather than all of the nodes being one big connected components. This is one of the more complex test cases for stronglyConnected(). The test case successfully showed that there are two connected components, and the output matches the expected vectors. 

7. The seventh test case stronglyConnected() is to test if the algorithm identifies a cycle with one node attached to it by an edge, and another node attached to the last node by another edge as two connected components. The same reasoning from the sixth test case is being tested by this test case, because out graph stores directed edges, the last node that is attached does not count as part of the connected component of the cycle. The test case successfully showed that there are two connected components.
  
  
  
Test cases: 

Shortest Paths:

1.	The test case “reverse direction doesn’t work if there exists only one direction from one node to another” checks whether reverse direction could work if there is only one way from node A to node B. in this test, we only called addEdge function from node 1 to 2 and from 2 to 3. So if the shortestPath function is called from 3 to 1, the output will be empty.
  
2.	The test case “correctly find the shortest path of two nodes SIMPLE” checks the validity of the shortest path in the simplest way. Node 1 to 6 is a straight line with the least distance, and there is another path that will go through node 7, which is a point that deviated from the straight line and takes more distance to go. The output correctly produces 123456 as output after calling the shortestPath function.
  
3.	The test case “correctly find the shortest path of two nodes in graph_1 (both directions work)” checks whether from node A to node B and from node B to node A will produce the same route as the output, but the sequence of the nodes shown in the output vector will be in the reverse order. The conditions are that two neighboring nodes can be traveled in both directions, in another word, if addEdge A to B is used, addEdge B to A should always be used. The output did produce the same routes with reversed order of node sequence.
In this test case, the graph is more complicated than the “SIMPLE” test case above. Traveling from nodes 7 to 8 has multiple possible routes with different distances. The output exactly showed the correct routes with the least distance and with the correct sequence of nodes.
  
4.	The test case “correctly find the shortest path when disconnected” checks that calling the shortestPath function of two nodes in two disconnected graphs will produce an empty vector, which has a size 0.
  
5.	The test case “correctly find the shortest path when multiple edges involved” checks if there are two nodes that have multiple edges connected with different distances, the shortestPath function will discover that and select the least distance one. It did find the shortest route in this case. So when multiple edges are connected between two nodes, the function could select the least one.

  

  
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  DataSets and result:
 
 Data correction:
  we have two function included which are the edgeData and nodeData, and both read data from the file and take the data points out. For the nodeData, it contains  the node ID, x coordinate, and y coordinate in a row, and we just need to take the x and y out to locate the node location on the map; for the edgeData it is consisted of 4 parts edgeID, startNode, endNode, and the distance from start to end. What we do is take those data out and store them into our map, and we do operation (road_Network) on it. For the network, we use addEdge and addNode maped each points on the road map, then we used some helper function like StronglyConnected to help each data point are connected to each other, and used viewgraph to finish the PNG map. 
  
  The PNG resolution is not that ideal, so for the edges that we made are being cut somehow, and we tried to arrange the edge by editing the slope being round up for decimal above 0.5 and round down else case.Due to the nature of the large amount of dataset, there's also rounding of coordinates and they are all 1/10 of their orginal value for the canvas to draw. The different colors on the png file named "graphImage.png" (can be found at ./Code) is used to showcase the "strongly connected components", each set of color indicates a directed cycle.
  
   dataTest.cpp:
  
For testing the correctness and accuracy of our code, we have completed two parts: dataTest.cpp and roadTest.cpp. The dataTest file checks whether the input files (files containing the data of nodes and edges) are successfully loaded and is separated into testing node data and edge data. For each node in the node input file, the node ID, x coordinate, and y coordinate should all be positive. When the file is loaded, all the data with negative node ID, negative x, negative y coordinate will be eliminated based on the code we wrote and will not be stored into our map<int Coordinate>. Based on this, we created a test data file (the picture below) with several valid data sets, but also some other invalid ones.
  
  0 1.2 2.3
  
  1 3.4 -4.5
  
  -2 3 5
  
  3 2 4
  
  4 5.7 6
  
  5 5 8
  
For these sets of data, line two contains negative y coordinate and line three contains negative nodeID. So the final data sets that will be stored into our map<int Coordinate> will only have a size of 4. If the size is not equal to 4, or any negative numbers show in our map, the node test case will not be passed.

Edge data test is similar to node data test, except that edge data sets have four elements: edgeID, startNode, endNode, and distance. All of them should be positive. Similarly, we created a file (the picture below). In this case, line 4, 5, 7, 8 will all be eliminated and the data sets loaded to our map<int, EdgeData> have the size of 4.
  
  0 1 2 5
  
  1 2 3 6
  
  2 3 4 8
  
  3 -1 2 9
  
  4 7 8 -10
  
  5 4 9 10
  
  -6 5 7 8
  
  7 3 -1 5


  


