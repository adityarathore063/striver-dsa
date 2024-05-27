#include <bits/stdc++.h>
using namespace std;

int func(int i, int j)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    int left = func(i, j - 1);
    int right = func(i - 1, j);

    return left + right;
}

int func1(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 or j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int left = func(i, j - 1);
    int right = func(i - 1, j);

    return dp[i][j] = left + right;
}

int func2(int m, int n, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

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

    return dp[m-1][n-1];
}

int func3(int m, int n){
    vector<int>prev(n,0);
    for(int i = 0; i<m; i++){
        vector<int>temp(n,0);
        for(int j = 0; j<n; j++){
            if(i==0 and j==0){
                temp[j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if(i>0){
                up = prev[j];
            }
            if(j>0){
                left = temp[j-1];
            }
            temp[j] = up+left;
        }
        prev = temp;
    }
    return prev[n-1];
}

int main()
{

    // Given two values M and N, which represent a matrix[M][N].
    //  We need to find the total unique paths from the top-left cel
    //  l (matrix[0][0]) to the rightmost cell (matrix[M-1][N-1]).
    // At any cell we are allowed to move in only two directions:- bottom and right.
    int m, n;
    cin >> m >> n;

    return 0;
}