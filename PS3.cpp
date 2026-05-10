// A* Algorithm for 8-Puzzle Problem in C++

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

// Goal State
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Structure for Puzzle State
struct Node {
    vector<vector<int>> state;
    int x, y;      // Blank tile position
    int g, h;      // Cost and heuristic

    // Total cost
    int f() const {
        return g + h;
    }

    // Comparator for priority queue
    bool operator<(const Node& other) const {
        return f() > other.f();
    }
};

// Calculate Manhattan Distance Heuristic
int heuristic(vector<vector<int>> state) {
    int distance = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int value = state[i][j];

            if (value != 0) {
                int targetX = (value - 1) / 3;
                int targetY = (value - 1) % 3;

                distance += abs(i - targetX) + abs(j - targetY);
            }
        }
    }

    return distance;
}

// Convert matrix to string for visited checking
string serialize(vector<vector<int>> state) {
    string s = "";

    for (auto row : state)
        for (auto val : row)
            s += to_string(val);

    return s;
}

// A* Search Function
void solvePuzzle(vector<vector<int>> start) {

    priority_queue<Node> pq;
    set<string> visited;

    int startX, startY;

    // Find blank space
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (start[i][j] == 0) {
                startX = i;
                startY = j;
            }
        }
    }

    Node initial = {start, startX, startY, 0, heuristic(start)};
    pq.push(initial);

    // Possible moves
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {

        Node current = pq.top();
        pq.pop();

        // Goal check
        if (current.state == goal) {
            cout << "Goal State Reached!" << endl;
            return;
        }

        string key = serialize(current.state);

        if (visited.count(key))
            continue;

        visited.insert(key);

        // Generate neighbors
        for (int i = 0; i < 4; i++) {

            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < 3 &&
                newY >= 0 && newY < 3) {

                vector<vector<int>> newState = current.state;

                swap(newState[current.x][current.y],
                     newState[newX][newY]);

                Node neighbor = {
                    newState,
                    newX,
                    newY,
                    current.g + 1,
                    heuristic(newState)
                };

                pq.push(neighbor);
            }
        }
    }

    cout << "No Solution Found!" << endl;
}

int main() {

    // Initial State
    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    solvePuzzle(start);

    return 0;
}