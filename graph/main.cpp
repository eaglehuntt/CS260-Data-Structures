#include <iostream>

#include "graph_node.hpp"
#include "edge.hpp"
#include "graph.cpp"

using std::cout;
using std::endl;

int main() {    
    Graph graph = Graph();

    // Example from wikipedia
    // https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

    GraphNode* A = graph.add_node('A');
    GraphNode* B = graph.add_node('B');
    GraphNode* C = graph.add_node('C');
    GraphNode* D = graph.add_node('D');
    GraphNode* E = graph.add_node('E');
    GraphNode* F = graph.add_node('F');

    graph.add_edge(A, B, 7);
    graph.add_edge(A, C, 9);
    graph.add_edge(A, F, 14);

    graph.add_edge(B, C, 10);
    graph.add_edge(B, D, 15);

    graph.add_edge(C, D, 11);
    graph.add_edge(C, F, 2);

    graph.add_edge(D, E, 6);

    graph.add_edge(E, F, 9);


    graph.dijkstra(A, F);

    // graph.kruskal();


    // example in class
    /* Graph graph2 = Graph();

    GraphNode *Z = graph2.add_node('Z');
    GraphNode *Y = graph2.add_node('Y');
    GraphNode *X = graph2.add_node('X');

    graph2.add_edge(Z, Y, 7);
    graph2.add_edge(Y, X, 8);
    graph2.add_edge(Z, X, 9);

    graph2.dijkstra(Z); */
    
}