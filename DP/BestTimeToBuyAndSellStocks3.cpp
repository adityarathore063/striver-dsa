#include <bits/stdc++.h>
using namespace std;

int recurr(int index, int buy, vector<int> &arr, int n, int cap)
{
    if (cap == 0)
    {
        return 0;
    }
    if (index == n)
    {
        return 0;
    }
    int profit = 0;
    if (buy)
    {
        profit = max((-arr[index] + recurr(index + 1, 0, arr, n, cap)), recurr(index + 1, 1, arr, n, cap));
    }
    else
    {
        profit = max((arr[index] + recurr(index + 1, 1, arr, n, cap - 1)), recurr(index + 1, 0, arr, n, cap));
    }

    return profit;
}

int memor(int index, int buy, vector<int> &arr, int n, vector<vector<vector<int>>> &dp, int cap)
{
    if (cap == 0)
    {
        return 0;
    }
    if (index == n)
    {
        return 0;
    }
    if (dp[index][buy][cap] != -1)
    {
        return dp[index][buy][cap];
    }
    int profit = 0;
    if (buy)
    {
        profit = max((-arr[index] + memor(index + 1, 0, arr, n, dp, cap)), memor(index + 1, 1, arr, n, dp, cap));
    }
    else
    {
        profit = max((arr[index] + memor(index + 1, 1, arr, n, dp, cap - 1)), memor(index + 1, 0, arr, n, dp, cap));
    }

    return dp[index][buy][cap] = profit;
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

    cout << recurr(0, 1, arr, n, 2) << "\n";
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    cout << memor(0, 1, arr, n, dp, 2) << "\n";

    // Tabulation
    vector<vector<vector<int>>> dpp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max((-arr[index] + dpp[index + 1][0][cap]), dpp[index + 1][1][cap]);
                }
                else
                {
                    profit = max((arr[index] + dpp[index + 1][1][cap - 1]), dpp[index + 1][0][cap]);
                }

                dpp[index][buy][cap] = profit;
            }
        }
    }

    cout << dpp[0][1][2] << "\n";

    // Space optimization
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max((-arr[index] + after[0][cap]), after[1][cap]);
                }
                else
                {
                    profit = max((arr[index] + after[1][cap - 1]), after[0][cap]);
                }

                curr[buy][cap] = profit;
            }
        }
        after = curr;
    }
    cout << after[1][2] << "\n";

    return 0;
}