#include <bits/stdc++.h>
using namespace std;

// Using Recursion
int maxSum(int ind, vector<int> &arr)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    int pick = arr[ind] + maxSum(ind - 2, arr);
    int notPick = 0 + maxSum(ind - 1, arr);

    return max(pick, notPick);
}

// Using Memorization
int maxSum1(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = arr[ind] + maxSum(ind - 2, arr);
    int notPick = 0 + maxSum(ind - 1, arr);

    return dp[ind] = max(pick, notPick);
}

// Using Tabulation
int maxSum2(int ind, vector<int> &arr, vector<int> &dp)
{
    dp[0] = arr[0];
    for (int i = 1; i < ind; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[ind - 1];
}

// Using Space optimization
int maxSum3(int ind, vector<int> &arr)
{
    int prev = arr[0];
    int prev2 = 0;
    for (int i = 1; i < ind; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int notPick = 0 + prev;

        int curi = max(pick, notPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main()
{

    // Given an array of ‘N’  positive integers, we need to return the maximum sum of the
    // subsequence such that no two elements of the subsequence are adjacent elements in the array.
    // Note: A subsequence of an array is a list with elements of the array where some elements are
    // deleted ( or not deleted at all) and the elements should be in the same order in the subsequence as in the array.

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    cout << maxSum(n - 1, arr) << "\n";
    vector<int> dp(n, -1);
    // cout << maxSum1(n - 1, arr, dp) << "\n";

    // cout << maxSum2(n, arr, dp) << "\n";

    cout << maxSum3(n, arr) << "\n";

    return 0;
}