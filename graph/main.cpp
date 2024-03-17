#include <iostream>

#include "graph_node.hpp"
#include "edge.hpp"
#include "graph.cpp"

using std::cout;
using std::endl;

int main() {
    Graph graph = Graph();

    /* GraphNode *A = graph.add_node('A');
    GraphNode *B = graph.add_node('B');
    GraphNode *C = graph.add_node('C');

    graph.add_edge(A, B, 7);
    graph.add_edge(B, C, 8);
    graph.add_edge(A, C, 9);

    graph.dijkstra(A); */
    

    GraphNode* A = graph.add_node('A');
    GraphNode* B = graph.add_node('B');
    GraphNode* C = graph.add_node('C');
    GraphNode* D = graph.add_node('D');
    GraphNode* E = graph.add_node('E');
    GraphNode* F = graph.add_node('F');

    // Add edges from A to other nodes
    graph.add_edge(A, B, 7);
    graph.add_edge(A, C, 9);
    graph.add_edge(A, F, 14);

    // Add edges from B to other nodes (except A to avoid redundancy)
    graph.add_edge(B, C, 10);
    graph.add_edge(B, D, 15);

    // Add edges from C to other nodes (except A and B)
    graph.add_edge(C, D, 11);
    graph.add_edge(C, F, 2);

    graph.add_edge(D, E, 6);

    graph.add_edge(F, E, 9);
    // graph.add_edge(E, F, 9);


    graph.dijkstra(A);


    
}