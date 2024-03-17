#include "graph.hpp"
#include "graph_node.hpp"
#include "edge.hpp"
#include <unordered_map> // Add this for unordered_map
#include <functional> // Add this for std::greater
#include <utility> // Add this for std::pair

#include <algorithm> // Need to include this for std::find

using std::cout;
using std::endl;
using std::pair;
using std::unordered_map;
using std::priority_queue;
using std::greater;
using std::numeric_limits;
using std::sort;

Graph::Graph() {
    nodes = new vector<GraphNode*>;
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

// Requires source node. If destination node is nullptr, it will print the shortest path to every possible node
void Graph::dijkstra(GraphNode* source_node, GraphNode* destination_node) {
    // dist[GraphNode] -> int (weight)
    unordered_map<GraphNode*, int> dist;

    // Initialize distances and previous nodes
    unordered_map<GraphNode*, GraphNode*> prev;

    priority_queue<pair<int, GraphNode*>, vector<pair<int, GraphNode*>>, greater<pair<int, GraphNode*>>> PQ;

    for (auto& node : *nodes) {
        if (node == source_node) {
            dist[node] = 0; // Initialize source node distance to 0
        } else {
            dist[node] = numeric_limits<int>::max(); // Initialize other nodes to INT_MAX
        }
        prev[node] = nullptr; // Initialize previous node for each node

        PQ.push({dist[node], node});
    }

    while (!PQ.empty()) {
        pair<int, GraphNode*> current_node = PQ.top();
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

    if (destination_node == nullptr) {
        cout << "Shortest path from source to every node in graph" << endl;
        cout << "Shortest path from " << source_node->value << ":" << endl;
        for (const auto& pair : dist) {
            cout << "(" << source_node->value << " -> " << pair.first->value << ": " << pair.second << "), ";
        }
        cout << endl;
    } else {
        cout << "(" << source_node->value << " -> " << destination_node->value << ": " << dist[destination_node] << ")" << endl;
    }

}


void Graph::kruskal() {
    // referenced this pseudo code: https://en.wikipedia.org/wiki/Kruskal%27s_algorithm

    // Initialize the forest F as an empty set
    vector<Edge*> F;

    // Sort the edges in increasing order of weight
    sort(adjacency_list.begin(), adjacency_list.end(), [](Edge* a, Edge* b) {
        return a->weight < b->weight;
    });

    // Create a disjoint set for each node in the graph
    // for each v in G.V do
        // MAKE-SET(v)
    unordered_map<GraphNode*, GraphNode*> parent;
    for (auto node : *nodes) {
        parent[node] = node;
    }

    // Iterate over the sorted edges
    for (Edge* edge : adjacency_list) {
        GraphNode* u = edge->source;
        GraphNode* v = edge->destination;

        // Find the parent of u and v
        GraphNode* parent_u = parent[u];
        GraphNode* parent_v = parent[v];

        // If u and v are not in the same set, add the edge to the forest
        if (parent_u != parent_v) {
            F.push_back(edge);

            // Merge the sets containing u and v
            for (auto& pair : parent) {
                if (pair.second == parent_v) {
                    pair.second = parent_u;
                }
            }
        }
    }

    // Output the minimum spanning tree
    cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
    for (Edge* edge : F) {
        cout << edge->source->value << " - " << edge->destination->value << " : " << edge->weight << endl;
    }
}
