#pragma once

#include <vector>

#include "edge.hpp"

struct Edge;

struct GraphNode {
    char name;
    std::vector<Edge *> connected_to;
};