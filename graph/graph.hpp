#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#include "graph_node.hpp"
#include "edge.hpp"

using std::vector;
using std::cout;
using std::endl;

class Graph {
    // collection of nodes
    vector<GraphNode> nodes;

    // collection of edges
    vector<vector<Edge>> adjacency_list;

    // size

    // add node

    // add edge

    // remove node?  Should we remove dangling edges (this could be an optional parameter)

    // remove edge? (careful to remove edge pointer from each node that the edge connects)

    // shortest path (perhaps Djikstra's algorithm)

    // minimum spanning tree (perhaps Kruskal's algorithm)

    // helper functions?

};