#include <bits/stdc++.h>
using namespace std;

int recurr(int index, int buy, vector<int> &arr, int n)
{
    if (index == n)
    {
        return 0;
    }
    int profit = 0;
    if (buy)
    {
        profit = max((-arr[index] + recurr(index + 1, 0, arr, n)), recurr(index + 1, 1, arr, n));
    }
    else
    {
        profit = max((arr[index] + recurr(index + 1, 1, arr, n)), recurr(index + 1, 0, arr, n));
    }

    return profit;
}

int memor(int index, int buy, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }
    int profit = 0;
    if (buy)
    {
        profit = max((-arr[index] + memor(index + 1, 0, arr, n, dp)), memor(index + 1, 1, arr, n, dp));
    }
    else
    {
        profit = max((arr[index] + memor(index + 1, 1, arr, n, dp)), memor(index + 1, 0, arr, n, dp));
    }

    return dp[index][buy] = profit;
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    cout << recurr(0, 1, arr, n) << "\n";
    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << memor(0, 1, arr, n, dp) << "\n";

    // Tabulation
    vector<vector<int>> dpp(n + 1, vector<int>(2, 0));

    dpp[n][0] = dpp[n][1] = 0; // base case
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max((-arr[index] + dpp[index + 1][0]), dpp[index + 1][1]);
            }
            else
            {
                profit = max((arr[index] + dpp[index + 1][1]), dpp[index + 1][0]);
            }

            dpp[index][buy] = profit;
        }
    }

    cout << dpp[0][1] << "\n";

    // Space optimization
    vector<int> ahead(2, 0), curr(2, 0);
    ahead[0] = ahead[1] = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max((-arr[index] + ahead[0]), ahead[1]);
            }
            else
            {
                profit = max((arr[index] + ahead[1]), ahead[0]);
            }

            curr[buy] = profit;
        }

        ahead = curr;
    }

    cout << ahead[1] << "\n";

    return 0;
}