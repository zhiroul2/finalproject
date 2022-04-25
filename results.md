
Our leading question was:

Knowing the power of network analysis, we will represent network as graph structure. The motivation here is to implement actual application that can be useful in networks.
We will be mainly focusing on two leading questions:
First, how to find the shortest path between two nodes, given the coordinates of every node and the distances between every two nodes on the map.
Second, how to find an area that has the most concentrated nodes connections, seperate the disjoint area, and possibility color them in order to distinguish the structure of the graph.
Third, we might consider to store the weighted adjacency matrix to save space in memory and, if we have time, calculate the eigenvector and thus find the most "popular" node,which carries the most traffic and bring security concerns.
In order to solve these two problems, one algorithm is to find the shortest route and distance between two nodes, and another one is to find some nodes that has much more connections and degrees than other nodes (thus could find some areas that are more concentrated with nodes and edges).
We will use the dataset that contains the information of the x and y coordinates of every eixsted node in a city, the distance between two nodes, the nodeID, and the edgeID. We will be using these information to approach the leading questions raised above.
We will also represent the data in the form of a graph. 
