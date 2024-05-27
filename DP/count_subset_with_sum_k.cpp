#include <bits/stdc++.h>
using namespace std;

int subset_sum_equal_to_k(vector<int> &arr, int index, int target)
{
    if (index == 0){
        if(target==0 and arr[0]==0) return 2;
        if(target==0 or target==arr[0]) return 1;
        return 0;
    }

    int notTake = subset_sum_equal_to_k(arr, index - 1, target);
    int take = 0;
    if (target >= arr[index])
    {
        take = subset_sum_equal_to_k(arr, index - 1, target - arr[index]);
    }
    return (take + notTake);
}
int subset_sum_equal_to_k1(vector<int> &arr, vector<vector<int>> &dp, int index, int target)
{
    if (index == 0){
        if(target==0 and arr[0]==0) return 2;
        if(target==0 or target==arr[0]) return 1;
        return 0;
    }
    if(dp[index][target]!=-1)
        return dp[index][target];
    int notTake = subset_sum_equal_to_k1(arr, dp, index - 1, target);
    int take = 0;
    if (target >= arr[index])
    {
        take = subset_sum_equal_to_k1(arr, dp, index - 1, target - arr[index]);
    }
    return dp[index][target] = (take + notTake);
}
void tabulation(vector<int> &arr, vector<vector<int>> &dp, int n, int target){
    for(int i = 0; i<n; i++){
        dp[i][0] = 1;
    }
    if(arr[0]<=target) dp[0][arr[0]] = 1;
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=target; j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(j>= arr[i]){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = notTake + take;
        }
    }
    cout<<dp[n-1][target]<<"\n";
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
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    vector<vector<int>>dpp(n, vector<int>(k+1, 0));
    cout << subset_sum_equal_to_k(vec, n - 1, k) << "\n";
    cout << subset_sum_equal_to_k1(vec, dp, n - 1, k) << "\n";
    tabulation(vec,dpp,n,k);

    return 0;
}