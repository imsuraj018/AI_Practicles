// Graph Coloring using CSP (Backtracking + Branch & Bound)

#include <iostream>

using namespace std;

#define V 4   // Number of vertices

class GraphColoring
{
    int graph[V][V];

public:

    // Constructor
    GraphColoring(int g[V][V])
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                graph[i][j] = g[i][j];
            }
        }
    }

    // Check whether current color assignment is safe
    bool isSafe(int vertex, int color[], int c)
    {
        for (int i = 0; i < V; i++)
        {
            // Adjacent vertex has same color
            if (graph[vertex][i] == 1 &&
                color[i] == c)
            {
                return false;
            }
        }

        return true;
    }

    // Recursive Backtracking Function
    bool solveColoring(int vertex, int color[], int m)
    {
        // All vertices colored
        if (vertex == V)
            return true;

        // Try all colors
        for (int c = 1; c <= m; c++)
        {
            // Branch & Bound pruning
            if (isSafe(vertex, color, c))
            {
                // Assign color
                color[vertex] = c;

                // Recursive call
                if (solveColoring(vertex + 1, color, m))
                    return true;

                // Backtrack
                color[vertex] = 0;
            }
        }

        return false;
    }

    // Print solution
    void printSolution(int color[])
    {
        cout << "Vertex Colors:\n";

        for (int i = 0; i < V; i++)
        {
            cout << "Vertex "
                 << i
                 << " ---> Color "
                 << color[i]
                 << endl;
        }
    }

    // Main function
    void graphColoring(int m)
    {
        int color[V];

        // Initialize all colors as 0
        for (int i = 0; i < V; i++)
            color[i] = 0;

        // Solve coloring problem
        if (!solveColoring(0, color, m))
        {
            cout << "Solution does not exist";
            return;
        }

        printSolution(color);
    }
};

int main()
{
    // Graph represented using adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    GraphColoring gc(graph);

    gc.graphColoring(m);

    return 0;
}