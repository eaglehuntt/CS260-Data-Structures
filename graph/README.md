Design Idea:

A graph structure can be used for a map system. In this system, a location would be a node with
properties such as address, images, office hours, etc. Edges would represent roads, and their weight
would be calculated by distance, speed limit, traffic, incident reports, etc. This complex graph
would have the ability to use Dijkstra's algorithm to find the shortest route from a starting
location to the desired destination.

Design for assignment:

Class Graph:

nodes : vector of nodes in the graph
adjacency_list : vector of edges in the graph. (nodes adjacent to each other)
int number_of_vertices : size of graph

add_node : create a node and add it to the graph
add_edge : link 2 nodes together and create an edge object
dijkstra : run shortest path algorithm from source. Destination is optional
kruskal : run MST algorithm. Will print a minimum spanning tree

Tests:
test_add_node : attempt to add a node to the graph. Checks if done correctly
test_pass_edge : attems to add an edge to the graph, checks if nodes are properly connected

Time complexity:
add_node : O(1). Regardless of graph size, it takes the same computation power to run this method.
add_edge : O(1). Each operation takes the same time to run.
dijkstra : O((n + e) log(n)). It iterates over each node and each edge worst case. It also accesses
a priority queue which takes log(n) time.
kruskal : O(E log(E)). The sorting of edges takes the most computation time, and most sorting
algorithms are this time complexity.
