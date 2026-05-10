// Kruskal's Minimum Spanning Tree Algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure for edge
struct Edge
{
    int src, dest, weight;
};

// Comparator for sorting edges
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
class DisjointSet
{
    int parent[100];

public:
    DisjointSet(int n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find parent
    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union sets
    void unite(int x, int y)
    {
        parent[find(x)] = find(y);
    }
};

// Kruskal Algorithm
void kruskalMST(vector<Edge>& edges, int vertices)
{
    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    DisjointSet ds(vertices);

    cout << "Edges in Minimum Spanning Tree:\n";

    int totalCost = 0;

    for (Edge e : edges)
    {
        int u = ds.find(e.src);
        int v = ds.find(e.dest);

        // If no cycle formed
        if (u != v)
        {
            cout << e.src << " - "
                 << e.dest << " : "
                 << e.weight << endl;

            totalCost += e.weight;

            ds.unite(u, v);
        }
    }

    cout << "Total Cost = " << totalCost << endl;
}

int main()
{
    int vertices = 4;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, vertices);

    return 0;
}