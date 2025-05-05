#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V; 
    list<int>* adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void BFS(int start) {
        bool visited[V] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(5); 

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS starting from node 0: ";
    g.BFS(0);
    cout << endl;

    return 0;
}
