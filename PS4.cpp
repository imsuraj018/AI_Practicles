// A* Algorithm for Maze Pathfinding in C++

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Structure for each cell
struct Node {
    int x, y;
    int g, h;

    int f() const {
        return g + h;
    }

    // Comparator for priority queue
    bool operator<(const Node& other) const {
        return f() > other.f();
    }
};

// Heuristic Function (Manhattan Distance)
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// A* Search Function
void aStarMaze(vector<vector<int>> maze,
               pair<int, int> start,
               pair<int, int> goal) {

    int rows = maze.size();
    int cols = maze[0].size();

    priority_queue<Node> pq;

    vector<vector<bool>> visited(rows,
                                 vector<bool>(cols, false));

    // Start node
    pq.push({
        start.first,
        start.second,
        0,
        heuristic(start.first, start.second,
                  goal.first, goal.second)
    });

    // Directions: Up, Down, Left, Right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        // Skip visited nodes
        if (visited[x][y])
            continue;

        visited[x][y] = true;

        // Print visited node
        cout << "(" << x << "," << y << ") ";

        // Goal check
        if (x == goal.first && y == goal.second) {
            cout << "\nGoal Reached!" << endl;
            return;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {

            int newX = x + dx[i];
            int newY = y + dy[i];

            // Valid move check
            if (newX >= 0 && newX < rows &&
                newY >= 0 && newY < cols &&
                maze[newX][newY] == 0 &&
                !visited[newX][newY]) {

                int newG = current.g + 1;
                int newH = heuristic(newX, newY,
                                     goal.first, goal.second);

                pq.push({newX, newY, newG, newH});
            }
        }
    }

    cout << "No Path Found!" << endl;
}

int main() {

    // 0 = Path, 1 = Wall
    vector<vector<int>> maze = {
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal  = {4, 4};

    cout << "A* Path Traversal:\n";

    aStarMaze(maze, start, goal);

    return 0;
}