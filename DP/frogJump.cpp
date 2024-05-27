#include <bits/stdc++.h>
using namespace std;

// Using Recursion
int func(int ind, vector<int> &height)
{
    if (ind == 0)
        return 0;
    int left = func(ind - 1, height) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = func(ind - 2, height) + abs(height[ind] - height[ind - 2]);
    }
    return min(left, right);
}

// Using Memorization

int func1(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
    {
        return dp[ind];
    }

    int left = func(ind - 1, height) + abs(height[ind] - height[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
    {
        right = func(ind - 2, height) + abs(height[ind] - height[ind - 2]);
    }
    return dp[ind] = min(left, right);
}

// using Tabulation

int func2(int n, vector<int> &height, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int a = dp[i - 1] + abs(height[i] - height[i - 1]);
        int b = INT_MAX;
        if (i > 1)
        {
            b = dp[i - 2] + abs(height[i] - height[i - 2]);
        }

        dp[i] = min(a, b);
    }
    return dp[n - 1];
}

// Space optimization

int func3(int n, vector<int>&height){
    int prev = 0;
    int prev1 = 0;
    for(int i = 1; i<n; i++){
        int a = prev + abs(height[i] - height[i - 1]);
        int b = INT_MAX;
        if(i>1){
            b = prev1 + abs(height[i] - height[i - 2]);
        }

        int curi = min(a,b);
        prev1 = prev;
        prev = curi;
    }
    return prev;
}

int main()
{

    // Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the(N - 1) th stair.
    // At a time the frog can climb either one or two steps.A height[N] array is also given.Whenever the frog
    // jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i] - height[j]),
    // where abs() means the absolute difference.We need to return the minimum energy that can be used
    // by the frog to jump from stair 0 to stair N -1.

    int n;
    cin >> n;
    vector<int> height{30, 10, 60, 10, 60, 50};
    cout << func(n - 1, height) << "\n";

    vector<int> dp(n + 1, -1);

    cout << func1(n - 1, height, dp) << "\n";

    cout << func2(n, height, dp) << "\n";

    cout << func3(n, height) << "\n";

    return 0;
}