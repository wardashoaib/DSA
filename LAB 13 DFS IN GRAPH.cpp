#include <iostream>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Graph(int n) {
        adj.resize(n);
        visited.resize(n, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node) {
        visited[node] = true;
        cout << node << " ";
        for (int next : adj[node])
            if (!visited[next])
                dfs(next);
    }

    void startDFS(int start) {
        dfs(start);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS: ";
    g.startDFS(0);

    return 0;
}
