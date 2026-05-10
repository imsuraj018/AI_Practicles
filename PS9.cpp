// N-Queens Problem using Backtracking (CSP Approach)

#include <iostream>
#include <vector>

using namespace std;

class NQueens
{
    int N;
    vector<vector<int>> board;

public:

    NQueens(int n)
    {
        N = n;

        board.resize(N, vector<int>(N, 0));
    }

    // Check whether queen can be placed safely
    bool isSafe(int row, int col)
    {
        int i, j;

        // Check left side of current row
        for (i = 0; i < col; i++)
        {
            if (board[row][i] == 1)
                return false;
        }

        // Check upper diagonal
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 1)
                return false;
        }

        // Check lower diagonal
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
        {
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Recursive Backtracking Function
    bool solve(int col)
    {
        // All queens placed
        if (col >= N)
            return true;

        // Try placing queen in each row
        for (int i = 0; i < N; i++)
        {
            if (isSafe(i, col))
            {
                // Place queen
                board[i][col] = 1;

                // Recursive call
                if (solve(col + 1))
                    return true;

                // Backtrack
                board[i][col] = 0;
            }
        }

        return false;
    }

    // Print solution
    void printBoard()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }

    // Start solving
    void solveNQueens()
    {
        if (solve(0) == false)
        {
            cout << "Solution does not exist";
            return;
        }

        cout << "Solution for " << N << "-Queens Problem:\n\n";

        printBoard();
    }
};

int main()
{
    int N = 4;

    NQueens q(N);

    q.solveNQueens();

    return 0;
}