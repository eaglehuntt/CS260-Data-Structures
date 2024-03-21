#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>

#include "graph_node.hpp"
#include "edge.hpp"

using std::vector;
using std::cout;
using std::endl;

class Graph {

    public:
    // collection of nodes
    vector<GraphNode*> *nodes;

    // collection of edges
    vector<Edge *> adjacency_list;

    // size
    int number_of_vertices;

public:
    // Constructor
    Graph();

    // Destructor
    ~Graph();

    // add node
    GraphNode *add_node(char node_value);

    // add edge
    void add_edge(GraphNode* source, GraphNode* destination, int weight);

    // shortest path (perhaps Dijkstra's algorithm)
    // destination is optionally nullptr. If it is nullptr, it will cout all the paths and return -1
    // if destination node is provided, it will return the weight of the shortest path
    int dijkstra(GraphNode* source_node, GraphNode* destination_node); 

    // minimum spanning tree (perhaps Kruskal's algorithm)
    int kruskal(bool print);
};
