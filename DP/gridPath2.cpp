#include <bits/stdc++.h>
using namespace std;

int func(int i, int j, vector<vector<int>> &maze)
{
    if (i > 0 && j > 0 && maze[i][j] == -1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    int left = func(i, j - 1, maze);
    int right = func(i - 1, j, maze);

    return left + right;
}

int func1(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &maze)
{
    if (i > 0 && j > 0 && maze[i][j] == -1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int left = func1(i, j - 1, dp, maze);
    int right = func1(i - 1, j, dp, maze);

    return dp[i][j] = left + right;
}

int func2(int m, int n, vector<vector<int>> &dp, vector<vector<int>> &maze)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

int func3(int m, int n, vector<vector<int>> &maze)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {

            if (i > 0 && j > 0 && maze[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }
            if (i == 0 and j == 0)
            {
                temp[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
            {
                up = prev[j];
            }
            if (j > 0)
            {
                left = temp[j - 1];
            }
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n - 1];
}

int main()
{
    //     We are given an “N*M” Maze. The maze contains some obstacles.
    //      A cell is ‘blockage’ in the maze if its value is -1. 0 represents
    //       non-blockage. There is no path possible through a blocked cell.
    //      We need to count the total number of unique paths from the top-left
    //      corner of the maze to the bottom-right corner. At every cell,
    //      we can move either down or towards the right.

    int m, n;
    cin >> m >> n;

    return 0;
}