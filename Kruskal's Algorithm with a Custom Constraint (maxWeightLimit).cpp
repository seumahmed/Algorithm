// C++ program for Kruskal's Algorithm with a Custom Constraint (maxWeightLimit)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Data structure to represent a graph
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// Utility function to find the parent of a node
int findParent(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;
    return findParent(parent, parent[node]);
}

// Function to perform Union operation
void performUnion(vector<int>& parent, int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

// Comparator function to sort edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void KruskalMST(Graph graph, int maxWeightLimit) {
    vector<Edge> result;
    vector<int> parent(graph.V);

    // Initialize parent array
    for (int i = 0; i < graph.V; i++)
        parent[i] = i;

    // Sort edges by weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    for (Edge edge : graph.edges) {
        if (edge.weight <= maxWeightLimit) {
            int x = findParent(parent, edge.src);
            int y = findParent(parent, edge.dest);

            if (x != y) {
                result.push_back(edge);
                performUnion(parent, x, y);
            }
        }
    }

    // Display MST edges and total weight
    cout << "Minimum Spanning Tree Edges:" << endl;
    int totalWeight = 0;
    for (Edge edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    Graph graph;
    graph.V = 4; // Number of vertices
    graph.E = 5; // Number of edges

    // Edges with source, destination, and weight
      graph.edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
        };

    int maxWeightLimit =5; // Set the maximum allowable weight for an edge

    KruskalMST(graph, maxWeightLimit);

    return 0;
}
