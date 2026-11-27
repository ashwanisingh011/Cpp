#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to run DFS with parent tracking.
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;

        // Explore every adjacent vertex.
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited, adj)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }

        // No cycle found through current DFS path.
        return false;
    }

public:
    // Function to detect a cycle in an undirected graph.
    bool isCycle(int vertices, vector<vector<int>>& adj) {
        vector<int> visited(vertices, 0);

        // Start DFS from every component.
        for (int node = 0; node < vertices; node++) {
            if (!visited[node]) {
                if (dfs(node, -1, visited, adj)) {
                    return true;
                }
            }
        }

        // No component contains a cycle.
        return false;
    }
};

// Driver code.
int main() {
    int vertices = 4;
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};

    Solution sol;
    cout << (sol.isCycle(vertices, adj) ? "true" : "false");
    return 0;
}
