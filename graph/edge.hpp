#pragma once

#include "graph_node.hpp"

struct GraphNode;

struct Edge {
    GraphNode *source;
    GraphNode *destination;
    int weight;
};
