/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal
void BFS(vector<vector<int>>& graph, int start, vector<bool>& visited, vector<int>& componentNodes) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    componentNodes.push_back(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < graph[current].size(); ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                componentNodes.push_back(i);
            }
        }
    }
}

// Function to find the number of connected components & nodes
void findConnectedComponentsAndNodes(vector<vector<int>>& graph) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    vector<vector<int>> connectedComponents;

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            vector<int> componentNodes;
            BFS(graph, i, visited, componentNodes);
            connectedComponents.push_back(componentNodes);
        }
    }

    cout << "Number of Connected Components: " << connectedComponents.size() << endl;
    for (int i = 0; i < connectedComponents.size(); ++i) {
        cout << "Nodes in each Component " << i + 1 << ": ";
        for (int node : connectedComponents[i]) {
            cout << node << " ";
        }
        cout << endl;
    }
}

int main() {
    // Sample adjacency matrix representing an undirected graph

    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    findConnectedComponentsAndNodes(graph);

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS traversal
void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;

    // Traverse all the adjacent nodes of the current node
    for (int neighbor : graph[node]) {
        // If the neighbor is not visited, perform DFS on it
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

// Function to count the number of connected components in the graph
int countConnectedComponents(vector<vector<int>>& graph) {
    int n = graph.size(); // Number of nodes
    vector<bool> visited(n, false); // Mark all nodes as not visited
    int connectedComponents = 0; // Initialize count of connected components

    // Traverse all nodes
    for (int i = 0; i < n; ++i) {
        // If the current node is not visited, perform DFS starting from it
        if (!visited[i]) {
            DFS(i, graph, visited);
            connectedComponents++; // Increment count of connected components
        }
    }

    return connectedComponents;
}

int main() {
    // Example graph representation (adjacency list)
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 1},     // Node 1 is connected to nodes 0 and 1
        {0, 1, 4},  // Node 2 is connected to nodes 0, 1, and 4
        {3},        // Node 3 is connected to node 3
        {5},        // Node 4 is connected to node 5
        {5, 6},     // Node 5 is connected to nodes 5 and 6
        {5}         // Node 6 is connected to node 5

    };

    int numConnectedComponents = countConnectedComponents(graph);

    cout << "Number of connected components: " << numConnectedComponents << endl;

return 0;
}


