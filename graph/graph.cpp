#include "graph.hpp"
#include "graph_node.hpp"
#include "edge.hpp"
#include <unordered_map> // Add this for unordered_map
#include <functional> // Add this for std::greater
#include <utility> // Add this for std::pair

#include <algorithm> // Need to include this for std::find

using std::cout;
using std::endl;

Graph::Graph() {
    nodes = new std::vector<GraphNode*>;
    number_of_vertices = 0;
}

Graph::~Graph() {
    for (GraphNode* node : *nodes) {
        delete node; // Delete each GraphNode object
    }
    delete nodes; // Delete the vector itself
}

GraphNode* Graph::add_node(char node_value) {
    // Create a new GraphNode with the given value
    GraphNode* new_node = new GraphNode{node_value};

    // Add a pointer to the new node to the collection of nodes
    nodes->push_back(new_node);

    // Increment the number of vertices
    number_of_vertices++;

    return new_node;
}

void Graph::add_edge(GraphNode *source, GraphNode *destination, int weight) {
    // Create a new edge
    Edge* new_edge = new Edge{source, destination, weight};

    // Add the edge to the source node's connected_to vector
    source->connected_to.push_back(new_edge);
    destination->connected_to.push_back(new_edge);

    // Update adjacency list
    adjacency_list.push_back(new_edge);

}

void Graph::dijkstra(GraphNode* source_node) {
    // dist[GraphNode] -> int (weight)
    std::unordered_map<GraphNode*, int> dist;

    // Initialize distances and previous nodes
    std::unordered_map<GraphNode*, GraphNode*> prev;

    std::priority_queue<std::pair<int, GraphNode*>, std::vector<std::pair<int, GraphNode*>>, std::greater<std::pair<int, GraphNode*>>> PQ;

    for (auto& node : *nodes) {
        if (node == source_node) {
            dist[node] = 0; // Initialize source node distance to 0
        } else {
            dist[node] = std::numeric_limits<int>::max(); // Initialize other nodes to INT_MAX
        }
        prev[node] = nullptr; // Initialize previous node for each node

        PQ.push({dist[node], node});
    }

    while (!PQ.empty()) {
        std::pair<int, GraphNode*> current_node = PQ.top();
        PQ.pop();

        GraphNode* u = current_node.second;

        for (Edge* edge : u->connected_to) { // Iterate only over neighbors of the current node
            
            // if edge->source == u then v = edge->destination else v = edge-> source
            GraphNode* v = (edge->source == u) ? edge->destination : edge->source; 

            int alt = dist[u] + edge->weight;

            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;

                // Update priority queue by pushing the updated distance
                PQ.push({dist[v], v});
            }
        }
    }

    std::cout << "Shortest path from " << source_node->value << ":" << std::endl;
    for (const auto& pair : dist) {
        std::cout << "(" << source_node->value << " -> " << pair.first->value << ": " << pair.second << "), ";
    }
    std::cout << std::endl;
}
