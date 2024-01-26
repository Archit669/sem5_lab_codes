#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

const int INF = INT_MAX; // Represents infinity

// Structure to represent a weighted edge
struct Edge {
    int dest, weight;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int V, int src) {
    vector<int> distance(V, INF); // Initialize distances to infinity
    distance[src] = 0; // Distance from the source to itself is 0

    set<pair<int, int>> minHeap; // A set to maintain vertices with minimum distances

    minHeap.insert({0, src});

    while (!minHeap.empty()) {
        int u = minHeap.begin()->second;
        minHeap.erase(minHeap.begin());

        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;

            // Relaxation step
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                // Remove the old (if present) and insert the new distance
                minHeap.erase({distance[v], v});
                distance[v] = distance[u] + weight;
                minHeap.insert({distance[v], v});
            }
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

    vector<vector<Edge>> graph(V);

    cout << "Enter the source, destination, and weight of each edge:" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, V, src);

    return 0;
}
