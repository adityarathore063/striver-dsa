#include<bits/stdc++.h>
using namespace std;

int recur(vector<int> &price, int index, int N){
    if(index==0){
        return (N*price[0]);
    }
    int notTake = 0 + recur(price,index-1,N);
    int take = INT_MIN;
    int rodLength = index+1;
    if(rodLength<=N){
        take = price[index] + recur(price,index,(N-rodLength));
    }

    return max(take,notTake);
}

int memor(vector<int> &price, int index, int N,vector<vector<int>> &dp){
    if(index==0){
        return (N*price[0]);
    }
    if(dp[index][N]!=-1){
        return dp[index][N];
    }
    int notTake = 0 + memor(price,index-1,N,dp);
    int take = INT_MIN;
    int rodLength = index+1;
    if(rodLength<=N){
        take = price[index] + memor(price,index,(N-rodLength),dp);
    }

    return dp[index][N]= max(take,notTake);
}
int main(){

    int n;
    cin>>n;
    vector<int>price;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        price.push_back(ele);
    }
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    cout<<recur(price,n-1,n)<<"\n";
    cout<<memor(price,n-1,n,dp)<<"\n";

    //Tabulation
    vector<vector<int>> dpp(n,vector<int>(n+1,0));
    for(int i = 0; i<=n; i++){
        dpp[0][i] = i*price[0];
    }

    for(int i = 1; i<n; i++){
        for(int j = 0; j<=n; j++){
           int notTake = 0 + dpp[i-1][j];
            int take = INT_MIN;
            int rodLength = i+1;
            if(rodLength<=j){
                take = price[i] + dpp[i][j-rodLength];
            }

            dpp[i][j]= max(take,notTake); 
        }
    }
    cout<<dpp[n-1][n]<<"\n";
    return 0;
}