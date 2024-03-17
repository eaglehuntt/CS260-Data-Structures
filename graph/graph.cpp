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

void Graph::dijkstra(GraphNode* source_node) { // pass in source_node

    // dist[GraphNode] -> int (weight)
    std::unordered_map<GraphNode*, int> dist;

    // Initialize distances and previous nodes
    std::unordered_map<GraphNode*, GraphNode*> prev;

    /* 
        According to ChatGPT:

        std::priority_queue: This is a standard library container adapter class template that provides a priority queue, which is a data structure similar to a regular queue, but with each element having a priority associated with it. Elements with higher priority are served before elements with lower priority.

        <std::pair<int, GraphNode*>>: This is the type of elements stored in the priority queue. It's a std::pair where the first element is an integer (int) representing the priority, and the second element is a pointer to a GraphNode. This indicates that the priority queue will contain pairs where the first element is an integer (presumably representing some sort of priority) and the second element is a pointer to a GraphNode.

        std::vector<std::pair<int, GraphNode*>>: This is the underlying container used by the priority queue to store its elements. In this case, it's a std::vector of pairs of integers and pointers to GraphNode. The elements in the priority queue will be stored in this vector container.

        std::greater<std::pair<int, GraphNode*>>: This is the comparison function used to order the elements in the priority queue. In this case, it's std::greater, which means that elements with greater priority (i.e., lower integer values) will be served first. So, the priority queue will pop elements with the highest priority first.
     */

    std::priority_queue<std::pair<int, GraphNode*>, std::vector<std::pair<int, GraphNode*>>, std::greater<std::pair<int, GraphNode*>>> PQ;


    for (auto& node : *nodes) {
        if (node == source_node) {
            dist[node] = 0; // Initialize source node distance to 0
        } else {
            dist[node] = std::numeric_limits<int>::max(); // Initialize other nodes to INT_MAX
            prev[node] = nullptr;
        }
        PQ.push({dist[node], node});
    }
    
    // while PQ is not empty
    while (!PQ.empty()){ 
        // u ← Q.extract_min()
        std::pair<int, GraphNode*> current_node = PQ.top();
        PQ.pop();
        
        // second is referring to the second item in the pair, in this case the node
        GraphNode* u = current_node.second;

        for (Edge* edge : adjacency_list){ // for each neighbor that u is connected to

            if (edge->source == u) {
                int alt = dist[u] + edge->weight;
                // if the proposed alt path is less than the current shortest path
                if (alt < dist[edge->destination]) { 
                    // set the current shortest path to alt
                    dist[edge->destination] = alt;
                    
                    // then update the prev map at the destination to u
                    prev[edge->destination] = u;

                    //Q.decrease_priority(v, alt)
                    PQ.push({dist[edge->destination], edge->destination});
                }
           
            }
        }

    }

        std::cout << "Dist: ";
        for (const auto& pair : dist) {
            std::cout << "(" << pair.first->value << ": " << pair.second << "), ";
        }
        std::cout << std::endl;

        std::cout << "Prev: ";
        for (const auto& pair : prev) {
            if (pair.second != nullptr) {
                std::cout << "(" << pair.first->value << "->" << pair.second->value << "), ";
            } else {
                std::cout << "(" << pair.first->value << "->nullptr), ";
            }
        }
        std::cout << std::endl;
   }
