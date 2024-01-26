#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    vector<tuple<int, int, int>> primMST();

private:
    int V;
    vector<vector<pair<int, int>>> adj;

};

Graph::Graph(int vertices) {
    V = vertices;
    adj.resize(vertices);
}

void Graph::addEdge(int u, int v, int weight) {
    adj[u].emplace_back(v, weight);
    adj[v].emplace_back(u, weight);
}

vector<tuple<int, int, int>> Graph::primMST() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
    vector<bool> inMST(V, false);
    vector<tuple<int, int, int>> mst;

    // Start with the first vertex (can be any vertex)
    int startVertex = 0;
    inMST[startVertex] = true;

    // Add all edges of the startVertex to the minHeap
    for (const pair<int, int>& edge : adj[startVertex]) {
        minHeap.push(make_tuple(edge.second, startVertex, edge.first));
    }

    while (!minHeap.empty()) {
        auto [weight, u, v] = minHeap.top();
        minHeap.pop();

        if (inMST[v]) {
            continue; // Skip if adding this edge creates a cycle
        }

        inMST[v] = true;
        mst.emplace_back(u, v, weight);

        // Add all edges of the newly added vertex to the minHeap
        for (const pair<int, int>& edge : adj[v]) {
            if (!inMST[edge.first]) {
                minHeap.push(make_tuple(edge.second, v, edge.first));
            }
        }
    }

    return mst;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    vector<tuple<int, int, int>> mst = g.primMST();

    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        auto [u, v, weight] = edge;
        cout << "Edge: " << u << " - " << v << ", Weight: " << weight << endl;
    }

    return 0;
}
