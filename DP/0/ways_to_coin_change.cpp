#include<bits/stdc++.h>
using namespace std;
int a  = 1e9;
int recur(vector<int> &denom, int index, int target){
    if(index==0){
        if(target%denom[0]==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int notTake = recur(denom,index-1,target);
    int take = 0;
    if(target>=denom[index]){
        take = recur(denom,index,target-denom[index]);
    }

    return notTake+take;
}
int memor(vector<int> &denom, int index, int target,vector<vector<int>> &dp){
    if(index==0){
        if(target%denom[0]==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int notTake = memor(denom,index-1,target,dp);
    int take = 0;
    if(target>=denom[index]){
        take =  memor(denom,index,target-denom[index],dp);
    }

    return dp[index][target] = notTake+take;
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
            dpp[0][i] = 1;
        }
        else{
            dpp[0][i] = 0;
        }
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=target; j++){
            int notTake = dpp[i-1][j];
            int take = 0;
            if(target>=denom[i]){
                take = dpp[i][target-denom[i]];
            }

            dpp[i][j]=(notTake+take); 
        }
    }
    cout<<dpp[n-1][target]<<"\n";
    return 0;
}