Leading question :

Knowing the power of network analysis, we will represent network as graph structure. The motivation here is to implement actual application that can be useful in networks.

We will be mainly focusing on two leading questions:

First, how to find the shortest path between two nodes, given the coordinates of every node and the distances between every two nodes on the map.
Second, how to find an area that has the most concentrated nodes connections, seperate the disjoint area, and possibility color them in order to distinguish the structure of the graph.

Third, we might consider to store the weighted adjacency matrix to save space in memory and, if we have time, calculate the eigenvector and thus find the most "popular" node,which carries the most traffic and bring security concerns.

In order to solve these two problems, one algorithm is to find the shortest route and distance between two nodes, and another one is to find some nodes that has much more connections and degrees than other nodes (thus could find some areas that are more concentrated with nodes and edges).

We will use the dataset that contains the information of the x and y coordinates of every eixsted node in a city, the distance between two nodes, the nodeID, and the edgeID. We will be using these information to approach the leading questions raised above.

We will also represent the data in the form of a graph. 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

We answer the question by creating a RoadNetwork class.
We create  RoadNetwork class and store the lists of nodes(Node is an inner class for road_network class to better extract information and provide interface needed) as a vector<Node*>, each node contains an adjacency list as vector<Edge> where edge is also an inner class.
  

in our node class, we store the int Nodeid, double x_, double y_, vector<edge> adjLists, and in each edge class, it stores int start, int end, double distance.

Since we have no idea what's the order of the user's input of nodes, so we resize the dynamic array of nodes based on the node id.As a consequence of this type of behavior, there will be NULL in our Nodelist_(Another reason we use Node* instead of Node, we want avoid useless memory allocation on stack).
 
In order to visualize the graph, we store the double x_, double y_ as the maximum value of x coordinate and y coordinate.Since our dataset is too large, we times 0.1 to our x and y to keep the ratios. Meanwhile we also track the number of total edges as a class variable to show the general settings of the dataset in our graph.

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
  
  

  
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  DataSets and result:
 
 Data correction:
  
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


  


