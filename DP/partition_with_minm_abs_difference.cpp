#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;

    vector<int>vec;
    int sum = 0;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        sum+=ele;
        vec.push_back(ele);
    }
    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
    for(int i = 0; i<n; i++){
        dp[i][0] = true;
    }
    if(vec[0]<=sum) dp[0][vec[0]] = true;

    for(int i = 1; i<n; i++){
        for(int j = 1; j<=sum; j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(vec[i] <= j){
                take = dp[i-1][j-vec[i]];
            }
            dp[i][j] = take | notTake;
        }
    }
    int mini = 1e9;
    for(int s1 = 0; s1<=sum/2; s1++){
        if(dp[n-1][s1]){
            mini = min(mini, abs((sum-s1) - s1));
        }
    }
    cout<<mini<<"\n";
    return 0;
}