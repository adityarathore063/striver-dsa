#include<bits/stdc++.h>
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
int main(){

    int n;
    cin>>n;
    int sum = 0;
    vector<int>vec;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        sum+=ele;
        vec.push_back(ele);
    }
    vector<vector<int>>dp(n+1, vector<int>((sum/2)+1, -1));
    if(sum%2==1){
        cout<<"0\n";
    }
    else{
        cout<<subset_sum_equal_to_k(vec,n-1,sum/2)<<"\n";
        cout<<subset_sum_equal_to_k1(vec,dp,n-1,sum/2)<<"\n";

    }

    return 0;
}