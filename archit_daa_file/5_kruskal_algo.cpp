#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;

    // Constructor
    Edge(int source, int destination, int w) : src(source), dest(destination), weight(w) {}

    // Comparison operator for sorting
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v, int w);
    vector<Edge> kruskalMST();

private:
    int V;
    vector<Edge> edges;
};

Graph::Graph(int vertices) {
    V = vertices;
}

void Graph::addEdge(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
}

// Helper function to find the parent of a vertex using union-find
int findParent(vector<int>& parent, int v) {
    if (parent[v] == v)
        return v;
    return findParent(parent, parent[v]);
}

// Helper function to perform union of two subsets
void unionSets(vector<int>& parent, int u, int v) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);
    parent[rootU] = rootV;
}

vector<Edge> Graph::kruskalMST() {
    // Sort the edges in ascending order by weight
    sort(edges.begin(), edges.end());

    vector<Edge> mst;
    vector<int> parent(V);

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    for (const Edge& edge : edges) {
        int rootSrc = findParent(parent, edge.src);
        int rootDest = findParent(parent, edge.dest);

        // If including this edge does not create a cycle in the MST
        if (rootSrc != rootDest) {
            mst.push_back(edge);
            unionSets(parent, rootSrc, rootDest);
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

    vector<Edge> mst = g.kruskalMST();

    cout << "Minimum Spanning Tree:" << endl;
    for (const Edge& edge : mst) {
        cout << "Edge: " << edge.src << " - " << edge.dest << ", Weight: " << edge.weight << endl;
    }

    return 0;
}
