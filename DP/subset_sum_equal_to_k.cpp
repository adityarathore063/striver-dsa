#include <bits/stdc++.h>
using namespace std;

bool subset_sum_equal_to_k(vector<int> &arr, int index, int target)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (arr[index] == target);

    bool notTake = subset_sum_equal_to_k(arr, index - 1, target);
    bool take = false;
    if (target >= arr[index])
    {
        take = subset_sum_equal_to_k(arr, index - 1, target - arr[index]);
    }
    return (take or notTake);
}
bool subset_sum_equal_to_k1(vector<int> &arr, vector<vector<int>> &dp, int index, int target)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (arr[index] == target);
    if(dp[index][target]!=-1)
        return dp[index][target];
    bool notTake = subset_sum_equal_to_k1(arr, dp, index - 1, target);
    bool take = false;
    if (target >= arr[index])
    {
        take = subset_sum_equal_to_k1(arr, dp, index - 1, target - arr[index]);
    }
    return dp[index][target] = (take or notTake);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        vec.push_back(ele);
    }
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    vector<vector<bool>>tab(n+1, vector<bool>(k+1, 0));
    cout << subset_sum_equal_to_k(vec, n - 1, k) << "\n";
    cout << subset_sum_equal_to_k1(vec, dp, n - 1, k) << "\n";

    for(int i = 0; i<n; i++){
        tab[i][0] = true;
    }
    tab[0][vec[0]] = true;

    for(int i = 1; i<n; i++){
        for(int j = 1; j<=k; j++){
            bool notTake = tab[i-1][j];
            bool take = false;
            if(j>=vec[i]) take = tab[i-1][j-vec[i]];
            tab[i][j] = (take | notTake);

        }
    }
    cout<<"Hello\n";
    cout<<tab[n-1][k];
    return 0;
}