#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Graph {
    vector<vector<int>> adjMatrix;
    vector<string> landmarks;
    int n;

public:
    Graph(int nodes) : n(nodes), adjMatrix(nodes, vector<int>(nodes, 0)) {}

    void acceptLandmarks() {
        landmarks.resize(n);
        cout << "Enter names of landmarks:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Landmark " << i + 1 << ": ";
            cin >> landmarks[i];
        }
    }

    void acceptEdges() {
        cout << "Enter distances between landmarks (-1 for no direct connection):\n";
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cout << "Distance between " << landmarks[i] << " and " << landmarks[j] << ": ";
                int dist;
                cin >> dist;
                adjMatrix[i][j] = adjMatrix[j][i] = (dist == -1 ? numeric_limits<int>::max() : dist);
            }
        }
    }

    void displayMatrix() const {
        cout << "\nAdjacency Matrix:\n\t";
        for (const auto& lm : landmarks) cout << lm << "\t";
        cout << "\n";

        for (int i = 0; i < n; ++i) {
            cout << landmarks[i] << "\t";
            for (int j = 0; j < n; ++j) {
                cout << (adjMatrix[i][j] == numeric_limits<int>::max() ? -1 : adjMatrix[i][j]) << "\t";
            }
            cout << "\n";
        }
    }

    void dijkstra(const string& src, const string& dest) {
        vector<int> dist(n, numeric_limits<int>::max());
        vector<bool> visited(n, false);
        vector<int> prev(n, -1);

        int srcIdx = findIndex(src), destIdx = findIndex(dest);
        if (srcIdx == -1 || destIdx == -1) {
            cout << "Invalid source or destination.\n";
            return;
        }

        dist[srcIdx] = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                    u = j;
            }

            if (dist[u] == numeric_limits<int>::max())
                break;

            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                if (adjMatrix[u][v] != numeric_limits<int>::max() && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    prev[v] = u;
                }
            }
        }

        if (dist[destIdx] == numeric_limits<int>::max()) {
            cout << "No path exists from " << src << " to " << dest << ".\n";
        } else {
            cout << "Shortest distance: " << dist[destIdx] << "\nPath: ";
            printPath(destIdx, prev);
            cout << "\n";
        }
    }

private:
    int findIndex(const string& landmark) const {
        for (int i = 0; i < n; ++i) {
            if (landmarks[i] == landmark) return i;
        }
        return -1;
    }

    void printPath(int node, const vector<int>& prev) const {
        if (node == -1) return;
        printPath(prev[node], prev);
        cout << landmarks[node] << " ";
    }
};

int main() {
    int n;
    cout << "Enter number of landmarks: ";
    cin >> n;

    Graph g(n);
    int choice;
    do {
        cout << "\n1. Accept landmarks\n2. Accept distances\n3. Display adjacency matrix\n4. Find shortest path\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.acceptLandmarks();
            break;
        case 2:
            g.acceptEdges();
            break;
        case 3:
            g.displayMatrix();
            break;
        case 4: {
            string src, dest;
            cout << "Enter source landmark: ";
            cin >> src;
            cout << "Enter destination landmark: ";
            cin >> dest;
            g.dijkstra(src, dest);
            break;
        }
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
