#include<bits/stdc++.h>
using namespace std;

int recur(vector<int> &weight, vector<int> &value, int index, int cap){
    if(index==0){
        // if(weight[0]<=cap){
        //     return value[0];
        // }
        // else{
        //     return 0;
        // }
        return ((cap/weight[0])*value[0]);
    }
    int notTake = 0 + recur(weight,value,index-1,cap);
    int take = INT_MIN;
    if(cap>=weight[index]){
        take = value[index] + recur(weight,value,index,cap-weight[index]);
    }
    return max(take,notTake);
}

int memor(vector<int> &weight, vector<int> &value, int index, int cap,vector<vector<int>> &dp){
    if(index==0){
        // if(weight[0]<=cap){
        //     return value[0];
        // }
        // else{
        //     return 0;
        // }
        return ((cap/weight[0])*value[0]);
    }
    if(dp[index][cap]!=-1){
        return dp[index][cap];
    }
    int notTake = 0 + memor(weight,value,index-1,cap,dp);
    int take = INT_MIN;
    if(cap>=weight[index]){
        take = value[index] + memor(weight,value,index-1,cap-weight[index],dp);
    }
    return dp[index][cap]=max(take,notTake);
}

int main(){

    int n,cap;
    cin>>n>>cap;
    vector<int>weight;
    vector<int>value;
    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;
        weight.push_back(x);
        value.push_back(y);
    }

    cout<<recur(weight,value,n-1,cap)<<"\n";
    vector<vector<int>>dp(n,vector<int>(cap+1,-1));
    cout<<memor(weight,value,n-1,cap,dp)<<"\n";

    //Tabulation
    vector<vector<int>>dpp(n,vector<int>(cap+1,0));
    for(int i = 0; i<=cap; i++){
        dpp[0][i] = ((cap/weight[0])*value[0]);
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=cap; j++){
            int notTake = 0 + dpp[i-1][j];
            int take = INT_MIN;
            if(j>=weight[i]){
                take = value[i] + dpp[i][j-weight[i]];
            }
            dpp[i][j]=max(take,notTake);
        }
    }
    cout<<dpp[n-1][cap]<<"\n";

    // Space optimize
    vector<int>prev(cap+1,0),curr(cap+1,0);
    for(int i = 0; i<=cap; i++){
        prev[i] = ((cap/weight[0])*value[0]);
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=cap; j++){
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if(j>=weight[i]){
                take = value[i] + prev[j-weight[i]];
            }
            curr[j]=max(take,notTake);
        }
        prev = curr;
    }
    cout<<prev[cap]<<"\n";
    return 0;
}