#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void primMST(int graph[5][5], int V) {
    int parent[V], key[V];
    bool mstSet[V] = {false};

    for (int i = 0; i < V; i++) key[i] = INT_MAX, parent[i] = -1;
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, u;

        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < minKey) minKey = key[v], u = v;

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

int main() {
    int graph[5][5] = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};
    primMST(graph, 5);
    return 0;
}
