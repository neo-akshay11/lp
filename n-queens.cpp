#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int col, int n)
{
    if (col >= n)
    {
        cout << "Solution found:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            // cout << "Placing queen at (" << i << ", " << col << ")\n";

            // res = solveNQueens(board, col + 1, n) || res;
            solveNQueens(board, col + 1, n);

            // if (!res)
            // {
            //     cout << "Backtracking from (" << i << ", " << col << ")\n";
            // }

            board[i][col] = 0;
        }
    }

    // return res;
    return true;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueens(board, 0, n))
    {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}
