#include <iostream>

#include "graph_node.hpp"
#include "edge.hpp"
#include "graph.cpp"

using std::cout;
using std::endl;

bool test_add_node() {
    bool passed = true; // Initialize passed as true
    Graph graph;

    // Test adding single node
    GraphNode* nodeA = graph.add_node('A');
    if (!(nodeA != nullptr && nodeA->value == 'A' && graph.number_of_vertices == 1)) {
        passed = false;
    }

    // Test adding multiple nodes
    GraphNode* nodeB = graph.add_node('B');
    GraphNode* nodeC = graph.add_node('C');
    if (!(nodeB != nullptr && nodeC != nullptr && graph.number_of_vertices == 3 &&
          nodeB->value == 'B' && nodeC->value == 'C')) {
        passed = false;
    }

    // Output test result
    if (passed) {
        cout << "test_add_node: Passed" << endl;
    } else {
        cout << "test_add_node: Failed" << endl;
    }

    return passed;
}

bool test_add_edge() {
    Graph graph;
    bool passed = true;

    // Adding nodes
    GraphNode* nodeA = graph.add_node('A');
    GraphNode* nodeB = graph.add_node('B');
    GraphNode* nodeC = graph.add_node('C');

    // Test adding edge
    graph.add_edge(nodeA, nodeB, 5);
    if (nodeA->connected_to.size() != 1 ||
        nodeB->connected_to.size() != 1 ||
        graph.adjacency_list.size() != 1)
        passed = false;

    // Test adding another edge
    graph.add_edge(nodeB, nodeC, 10);
    if (nodeB->connected_to.size() != 2 ||
        nodeC->connected_to.size() != 1 ||
        graph.adjacency_list.size() != 2)
        passed = false;

     // Output test result
    if (passed) {
        cout << "test_add_edge: Passed" << endl;
    } else {
        cout << "test_add_edge: Failed" << endl;
    }
    return passed;
}


int main() {    

    cout << "Running tests..." << endl;
    if (test_add_node() && test_add_edge()) {
        cout << "All tests passed... Running example code" << endl;
    } else {
        cout << "Tests failed. Exiting" << endl;
        return -1;
    }
    Graph graph = Graph();

    // Example graph from wikipedia
    // https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

    cout << "Graph from wikipedia: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm" << endl;
    cout << endl;
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


    graph.dijkstra(A, nullptr);
    graph.kruskal();

    cout << endl;
    cout << "Graph 1 from source 'C' to destination 'F': " << endl;
    graph.dijkstra(C, F);

    // example in class
    cout << endl;
    cout << "Graph from class:" << endl;
    cout << endl;
    Graph graph2 = Graph();

    GraphNode *Z = graph2.add_node('Z');
    GraphNode *Y = graph2.add_node('Y');
    GraphNode *X = graph2.add_node('X');

    graph2.add_edge(Z, Y, 7);
    graph2.add_edge(Y, X, 8);
    graph2.add_edge(Z, X, 9);

    graph2.dijkstra(Z, nullptr);
    graph2.kruskal();
}