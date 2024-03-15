#pragma once

#include <vector>

#include "edge.hpp"

struct Edge;

struct GraphNode {
    char value;
    std::vector<Edge *> connected_to;
};