#include <bits/stdc++.h>
using namespace std;

// Using Recursion
int fibb(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibb(n - 1) + fibb(n - 2);
}

// Using Dynamic Programming (Memorization)
int fibb1(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibb1(n - 1, dp) + fibb1(n - 2, dp);
}

// Using Dynamic Programming (Tabulation)

int fibb2(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space optimized

int fibb3(int n){
    if(n<=1){
        return n;
    }
    int prev = 1;
    int prev2 = 0;
    for(int i = 2; i<=n; i++){
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fibb(i) << " ";
    }
    cout << "\n";
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        cout << fibb1(i, dp) << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << fibb2(i, dp) << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << fibb3(i) << " ";
    }

    return 0;
}