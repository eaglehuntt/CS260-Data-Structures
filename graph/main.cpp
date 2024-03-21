#include <iostream>
#include <sstream>

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

bool test_add_node_2() {
    bool passed = true;
    Graph graph;

    // Test adding single node
    GraphNode* nodeG = graph.add_node('G');
    if (!(nodeG != nullptr && nodeG->value == 'G' && graph.number_of_vertices == 1)) {
        passed = false;
    }

    // Test adding multiple nodes
    GraphNode* nodeH = graph.add_node('H');
    GraphNode* nodeI = graph.add_node('I');
    if (!(nodeH != nullptr && nodeI != nullptr && graph.number_of_vertices == 3 &&
          nodeH->value == 'H' && nodeI->value == 'I')) {
        passed = false;
    }

    // Output test result
    if (passed) {
        cout << "test_add_node_2: Passed" << endl;
    } else {
        cout << "test_add_node_2: Failed" << endl;
    }

    return passed;
}

bool test_add_edge_2() {
    Graph graph;
    bool passed = true;

    // Adding nodes
    GraphNode* nodeG = graph.add_node('G');
    GraphNode* nodeH = graph.add_node('H');
    GraphNode* nodeI = graph.add_node('I');

    // Test adding edge
    graph.add_edge(nodeG, nodeH, 5);
    if (nodeG->connected_to.size() != 1 ||
        nodeH->connected_to.size() != 1 ||
        graph.adjacency_list.size() != 1)
        passed = false;

    // Test adding another edge with the same nodes and different weight
    graph.add_edge(nodeG, nodeH, 8);
    if (nodeG->connected_to.size() != 1 ||
        nodeH->connected_to.size() != 1 ||
        graph.adjacency_list.size() != 1 ||
        nodeG->connected_to[0]->weight != 8) {
            passed = false;
        }

    // Output test result
    if (passed) {
        cout << "test_add_edge_2: Passed" << endl;
    } else {
        cout << "test_add_edge_2: Failed" << endl;
    }
    return passed;
}

bool test_dijkstra() {
    bool passed;

    // Create a Graph object
    Graph graph;

    // Add nodes
    GraphNode* nodeA = graph.add_node('A');
    GraphNode* nodeB = graph.add_node('B');
    GraphNode* nodeC = graph.add_node('C');
    GraphNode* nodeD = graph.add_node('D');

    // Add edges
    graph.add_edge(nodeA, nodeB, 1);
    graph.add_edge(nodeA, nodeC, 3);
    graph.add_edge(nodeB, nodeC, 2);
    graph.add_edge(nodeB, nodeD, 4);
    graph.add_edge(nodeC, nodeD, 5);

    int expected_output = 3; // A -> C
    int actual_output = graph.dijkstra(nodeA, nodeC);

    if (expected_output == actual_output) {
        std::cout << "test_dijkstra: Passed\n";
        passed = true;
    } else {
        std::cout << "test_dijkstra: Failed\n";
        passed = false;
    }

    return passed;
}

bool test_dijkstra_2() {
    bool passed;

    // Create a Graph object
    Graph graph;

    // Add nodes
    GraphNode* nodeA = graph.add_node('A');
    GraphNode* nodeB = graph.add_node('B');
    GraphNode* nodeC = graph.add_node('C');
    GraphNode* nodeD = graph.add_node('D');

    // Add edges
    graph.add_edge(nodeA, nodeB, 2);
    graph.add_edge(nodeA, nodeC, 3);
    graph.add_edge(nodeB, nodeC, 1);
    graph.add_edge(nodeB, nodeD, 4);
    graph.add_edge(nodeC, nodeD, 2);

    int expected_output = 3; // A -> C
    int actual_output = graph.dijkstra(nodeA, nodeC);

    if (expected_output == actual_output) {
        std::cout << "test_dijkstra_2: Passed\n";
        passed = true;
    } else {
        std::cout << "test_dijkstra_2: Failed\n";
        passed = false;
    }

    return passed;
}

struct MinimumSpanningTree {
    std::vector<Edge*> edges;
    int totalWeight;
};

// Test function for Kruskal's algorithm
bool test_kruskal() {
    // Initialize passed to true
    bool passed = true;

    // Create a Graph object
    Graph graph;

    // Add nodes
    GraphNode* nodeA = graph.add_node('A');
    GraphNode* nodeB = graph.add_node('B');
    GraphNode* nodeC = graph.add_node('C');
    GraphNode* nodeD = graph.add_node('D');

    // Add edges
    graph.add_edge(nodeA, nodeB, 1);
    graph.add_edge(nodeA, nodeC, 3);
    graph.add_edge(nodeB, nodeC, 2);
    graph.add_edge(nodeB, nodeD, 4);
    graph.add_edge(nodeC, nodeD, 5);

    // Manually make an MST struct
    MinimumSpanningTree expectedMST;
    expectedMST.edges.push_back(new Edge{nodeA, nodeB, 1});
    expectedMST.edges.push_back(new Edge{nodeB, nodeC, 2});
    expectedMST.edges.push_back(new Edge{nodeB, nodeD, 4});
    expectedMST.totalWeight = 7;

    // Run Kruskal's algorithm
    int actualMST = graph.kruskal(false);

    // Compare expected output with actual output
    if (expectedMST.totalWeight != actualMST) {
        // If total weight or number of edges differs, test failed
        passed = false;
    }

    // Output test result
    if (passed) {
        std::cout << "test_kruskal: Passed" << std::endl;
    } else {
        std::cout << "test_kruskal: Failed" << std::endl;
    }

    // Deallocate memory for edges in expectedMST
    for (auto edge : expectedMST.edges) {
        delete edge;
    }

    return passed;
}

bool test_kruskal_2() {
    // Initialize passed to true
    bool passed = true;

    // Create a Graph object
    Graph graph;

    // Add nodes
    GraphNode* nodeA = graph.add_node('A');
    GraphNode* nodeB = graph.add_node('B');
    GraphNode* nodeC = graph.add_node('C');
    GraphNode* nodeD = graph.add_node('D');
    GraphNode* nodeE = graph.add_node('E');

    // Add edges
    graph.add_edge(nodeA, nodeB, 4);
    graph.add_edge(nodeA, nodeC, 8);
    graph.add_edge(nodeB, nodeC, 7);
    graph.add_edge(nodeB, nodeD, 9);
    graph.add_edge(nodeB, nodeE, 10);
    graph.add_edge(nodeC, nodeD, 4);
    graph.add_edge(nodeC, nodeE, 5);
    graph.add_edge(nodeD, nodeE, 6);

    // Manually make an MST struct
    MinimumSpanningTree expectedMST;
    expectedMST.edges.push_back(new Edge{nodeA, nodeB, 4});
    expectedMST.edges.push_back(new Edge{nodeB, nodeC, 7});
    expectedMST.edges.push_back(new Edge{nodeC, nodeD, 4});
    expectedMST.edges.push_back(new Edge{nodeC, nodeE, 5});
    expectedMST.edges.push_back(new Edge{nodeD, nodeE, 6});
    expectedMST.totalWeight = 20;

    // Run Kruskal's algorithm
    int actualMST = graph.kruskal(false);

    // Compare expected output with actual output
    if (expectedMST.totalWeight != actualMST) {
        // If total weight or number of edges differs, test failed
        passed = false;
    }

    // Output test result
    if (passed) {
        std::cout << "test_kruskal_2: Passed" << std::endl;
    } else {
        std::cout << "test_kruskal_2: Failed" << std::endl;
    }

    // Deallocate memory for edges in expectedMST
    for (auto edge : expectedMST.edges) {
        delete edge;
    }

    return passed;
}



bool run_tests() {
    bool passed = (test_add_node() && test_add_edge() && test_add_node_2() && test_add_edge_2() && test_dijkstra() && test_kruskal() && test_dijkstra_2() && test_kruskal_2());
    return passed;
}


int main() {    

    cout << "Running tests..." << endl;
    if (run_tests()) {
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
    graph.kruskal(true);

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
    graph2.kruskal(true);
}