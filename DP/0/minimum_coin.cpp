#include<bits/stdc++.h>
using namespace std;
int a  = 1e9;
int recur(vector<int> &denom, int index, int target){
    if(index==0){
        if(target%denom[index]==0){
            return target/denom[index];
        }
        else{
            return 1e9;
        }
    }
    int notTake = 0 + recur(denom,index-1,target);
    int take = INT_MAX;
    if(target>=denom[index]){
        take = 1 + recur(denom,index,target-denom[index]);
    }

    return min(notTake,take);
}
int memor(vector<int> &denom, int index, int target,vector<vector<int>> &dp){
    if(index==0){
        if(target%denom[0]==0){
            return target/denom[index];
        }
        else{
            return 1e9;
        }
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int notTake = memor(denom,index-1,target,dp);
    int take = INT_MAX;
    if(target>=denom[index]){
        take = 1 + memor(denom,index,target-denom[index],dp);
    }

    return dp[index][target] = min(notTake,take);
}
int main(){

    int n,target;
    cin>>n>>target;
    vector<int>denom;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        denom.push_back(ele);
    }
    cout<<recur(denom,n-1,target)<<"\n";

    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    cout<<memor(denom,n-1,target,dp)<<"\n";

    // Tabulation
    vector<vector<int>> dpp(n,vector<int>(target+1,0));
    for(int i = 0; i<=target; i++){
        if(i%denom[0]==0){
            dpp[0][i] = target/denom[0];
        }
        else{
            dpp[0][i] = 1e9;
        }
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=target; j++){
            int notTake = dpp[i-1][j];
            int take = INT_MAX;
            if(target>=denom[i]){
                take = 1 + dpp[i][target-denom[i]];
            }

            dpp[i][j]=min(notTake,take); 
        }
    }
    cout<<dpp[n-1][target]<<"\n";
    return 0;
}