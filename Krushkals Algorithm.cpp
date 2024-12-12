#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u) 
            parent[u] = find(parent[u]); // Path compression
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void kruskal(int V, vector<Edge>& edges) {
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());

    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (Edge& e : edges) {
        int u = e.u, v = e.v;

        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mstWeight += e.weight;
            mstEdges.push_back(e);
        }
    }

    // Output the edges of the MST
    cout << "Minimum Spanning Tree:\n";
    for (Edge& e : mstEdges) {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges in the format u v weight:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(V, edges);

    return 0;
}
