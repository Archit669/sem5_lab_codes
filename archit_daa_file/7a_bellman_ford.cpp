#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to implement the Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int V, int E, int src) {
    // Initialize distances from the source to all vertices as infinity
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }

    // Print the distances from the source vertex
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(edges, V, E, src);

    return 0;
}
