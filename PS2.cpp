// Depth First Search (DFS) using Recursion in C++
// Undirected Graph Implementation

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Recursive DFS function
void dfsRecursive(unordered_map<int, vector<int>>& graph,
                  int vertex,
                  unordered_set<int>& visited)
{
    // Mark current vertex as visited
    visited.insert(vertex);

    // Print current vertex
    cout << vertex << " ";

    // Visit all adjacent vertices
    for (int neighbor : graph[vertex])
    {
        // If not visited, recursively visit
        if (visited.find(neighbor) == visited.end())
        {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

int main()
{
    // Undirected Graph
    unordered_map<int, vector<int>> graph;

    graph[1] = {2, 3};
    graph[2] = {1, 4, 5};
    graph[3] = {1, 6, 7};
    graph[4] = {2};
    graph[5] = {2};
    graph[6] = {3};
    graph[7] = {3};

    unordered_set<int> visited;

    int startVertex = 1;

    cout << "DFS Traversal: ";

    // Start DFS
    dfsRecursive(graph, startVertex, visited);

    return 0;
}