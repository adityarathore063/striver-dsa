#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    // same as previous question change only k
    vector<vector<int>> after(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
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
    cout << after[1][k] << "\n";

    return 0;
}