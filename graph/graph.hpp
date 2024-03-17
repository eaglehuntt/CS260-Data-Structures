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

    // remove node?  Should we remove dangling edges (this could be an optional parameter)
    void remove_node(char node_value);

    // remove edge? (careful to remove edge pointer from each node that the edge connects)
    void remove_edge(GraphNode* source, GraphNode* destination);

    // shortest path (perhaps Dijkstra's algorithm)
    void dijkstra(GraphNode* source_node, GraphNode* destination_node); // fix return type

    // minimum spanning tree (perhaps Kruskal's algorithm)
    void kruskal(); // fix return type

    // helper functions?
};
