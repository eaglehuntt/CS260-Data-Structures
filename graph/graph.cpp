#include "graph.hpp"
#include "graph_node.hpp"
#include "edge.hpp"

#include <algorithm> // Need to include this for std::find

Graph::Graph() {
    nodes = new vector<GraphNode>;
    adjacency_list = new vector<vector<Edge>>;
    number_of_vertices = 0;
}

// Destructor
Graph::~Graph() {
    delete nodes;
    delete adjacency_list;
}

void Graph::add_node(char node_value) {
    // Create a new GraphNode with the given value
    GraphNode* new_node = new GraphNode{node_value};

    // Add the new node to the collection of nodes
    nodes->push_back(*new_node);

    // Increment the number of vertices
    number_of_vertices++;

    // Update adjacency list with an empty vector for the new node (no edges yet)
    adjacency_list->push_back(vector<Edge>());
}

void Graph::add_edge(GraphNode *source, GraphNode *destination, int weight) {
    // Create a new edge
    Edge* new_edge = new Edge{source, destination, weight};

    // Add the edge to the source node's connected_to vector
    source->connected_to.push_back(new_edge);
    destination->connected_to.push_back(new_edge);
}

void Graph::remove_node(char node_value) {
    // Find the node with the specified value
    for (auto it = nodes->begin(); it != nodes->end(); ++it) {
        if ((*it).value == node_value) {
            
            for (auto edge : (*it).connected_to) { // for each edge it is connected to 
                
                /* 
                    - edge: a pointer to the edge being removed.
                    - edge->destination: accesses the destination node of the edge.
                    - edge->destination->connected_to: accesses the vector containing all edges connected to the destination node.
                    - std::find(...): This is the standard library function used to search for a value in a range defined by the iterators begin() and end().
                */

                // Remove edges connected to the node

                // Remove the edge from the destination node's connected_to vector
                auto destination_node = std::find(edge->destination->connected_to.begin(), edge->destination->connected_to.end(), edge);
                
                if (destination_node != edge->destination->connected_to.end()) {
                    edge->destination->connected_to.erase(destination_node);
                }
                // Deallocate memory for the edge
                delete edge;
            }
            // Erase the node from the vector of nodes
            nodes->erase(it);
            break;
        }
    }
}

void Graph::remove_edge(GraphNode *source, GraphNode *destination) {
    // Find the edge between the specified source and destination nodes
    for (auto it = source->connected_to.begin(); it != source->connected_to.end(); ++it) {
        if ((*it)->destination == destination) {
            // Remove the edge from the source node's connected_to vector
            source->connected_to.erase(it);
            
            // Find the edge in the destination node's connected_to vector
            auto destination_it = std::find(destination->connected_to.begin(), destination->connected_to.end(), *it);
            if (destination_it != destination->connected_to.end()) {
                // Remove the edge from the destination node's connected_to vector
                destination->connected_to.erase(destination_it);
            }
            break;
        }
    }
}