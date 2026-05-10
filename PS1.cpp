// Breadth First Search (BFS) using Recursion in C++
// Undirected Graph Implementation

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Recursive BFS function
void bfsRecursive(unordered_map<int, vector<int>>& graph,
                  queue<int>& q,
                  unordered_set<int>& visited)
{
    // Base condition
    if (q.empty())
        return;

    // Get front vertex
    int vertex = q.front();
    q.pop();

    // Print current vertex
    cout << vertex << " ";

    // Visit all adjacent vertices
    for (int neighbor : graph[vertex])
    {
        if (visited.find(neighbor) == visited.end())
        {
            visited.insert(neighbor);
            q.push(neighbor);
        }
    }

    // Recursive call
    bfsRecursive(graph, q, visited);
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

    queue<int> q;
    unordered_set<int> visited;

    int startVertex = 1;

    // Start BFS
    visited.insert(startVertex);
    q.push(startVertex);

    cout << "BFS Traversal: ";

    bfsRecursive(graph, q, visited);

    return 0;
}