#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Class to represent an edge
class Edge {
public:
    int destination;
    int weight;
    
    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Class to represent a graph node
class GraphNode {
public:
    int id;

    GraphNode(int _id) : id(_id) {}
};

// Class to represent a graph
class Graph {
public:
    int numVertices;
    vector<vector<Edge>> adjacencyList;
    vector<GraphNode> nodes;

    Graph(int numVertices) : numVertices(numVertices) {
        adjacencyList.resize(numVertices);
        nodes.reserve(numVertices);
        for (int i = 0; i < numVertices; ++i) {
            nodes.emplace_back(i);
        }
    }

    // Function to add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].emplace_back(destination, weight);
        // For undirected graph, add the reverse edge
        // adjacencyList[destination].emplace_back(source, weight);
    }

    // Function to get the weight of an edge between two vertices
    int getEdgeWeight(int u, int v) {
        for (const Edge& edge : adjacencyList[u]) {
            if (edge.destination == v)
                return edge.weight;
        }
        return numeric_limits<int>::max(); // No edge found
    }

    // Dijkstra's algorithm
    pair<vector<int>, vector<int>> dijkstra(int source) {
        vector<int> dist(numVertices, numeric_limits<int>::max());
        vector<int> prev(numVertices, -1); // -1 indicates undefined predecessor
        dist[source] = 0;

        auto compare = [&](int u, int v) { return dist[u] > dist[v]; };
        priority_queue<int, vector<int>, decltype(compare)> pq(compare);
        pq.push(source);

        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();

            for (const Edge& edge : adjacencyList[u]) {
                int v = edge.destination;
                int alt = dist[u] + edge.weight;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    pq.push(v);
                }
            }
        }

        return make_pair(dist, prev);
    }
};

int main() {
    // Create a graph with 4 vertices
    Graph graph(4);

    // Add some edges
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(1, 2, 20);
    graph.addEdge(2, 3, 30);

    // Run Dijkstra's algorithm from vertex 0
    int source = 0;
    auto result = graph.dijkstra(source);
    vector<int> dist = result.first;
    vector<int> prev = result.second;

    // Output the distances and predecessors
    for (int i = 0; i < graph.numVertices; ++i) {
        cout << "Distance from vertex " << source << " to " << i << ": " << dist[i] << endl;
        cout << "Predecessor of vertex " << i << ": " << prev[i] << endl;
    }

    return 0;
}
