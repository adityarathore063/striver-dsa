#include<bits/stdc++.h>
using namespace std;

int recurr(int i, int j, string s1, string s2){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(s1[i]==s2[j]){
        return recurr(i-1,j-1,s1,s2);
    }
    return 1+min(recurr(i-1,j,s1,s2),min(recurr(i,j-1,s1,s2),recurr(i-1,j-1,s1,s2)));
}

int memor(int i, int j, string s1, string s2, vector<vector<int>>&dp){
    if(i==0) return j;
    if(j==0) return i;

    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i-1]==s2[j-1]){
        return dp[i][j]= memor(i-1,j-1,s1,s2,dp);
    }
    return dp[i][j]= 1+min(memor(i-1,j,s1,s2,dp),min(memor(i,j-1,s1,s2,dp),memor(i-1,j-1,s1,s2,dp)));
}

int main(){

    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    cout<<recurr(n-1,m-1,s1,s2)<<"\n";

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    cout<<memor(n,m,s1,s2,dp)<<"\n";

    // Tabulation
    vector<vector<int>> dpp(n+1,vector<int>(m+1,-1));
    for(int i = 0; i<=n; i++) dpp[i][0] = i;
    for(int j = 0; j<=m; j++) dpp[0][j] = j;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dpp[i][j] = dpp[i-1][j-1];
            }
            else{
                dpp[i][j] = 1 + min(dpp[i-1][j],min(dpp[i][j-1],dpp[i-1][j-1]));
            }
        }
    }
    cout<<dpp[n][m]<<"\n";


    return 0;
}