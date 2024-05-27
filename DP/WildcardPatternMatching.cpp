#include<bits/stdc++.h>
using namespace std;

int recurr(int i, int j, string s1, string s2){
    if(i<0 and j<0) return true;
    if(i<0 and j>=0) return false;

    if(j<0 and i>=0){
        for(int ii = 0; ii<=i; ii++){
            if(s1[ii]!='*'){
                return false;
            }
        }
        return true;
    }


    if(s1[i]==s2[j]||s1[i]=='?'){
        return recurr(i-1,j-1,s1,s2);
    }

    if(s1[i]=='*'){
        return recurr(i-1,j,s1,s2) or recurr(i,j-1,s1,s2);
    }

    return false;
}

int memor(int i, int j, string s1, string s2,vector<vector<int>> &dp){
    if(i<0 and j<0) return true;
    if(i<0 and j>=0) return false;

    if(j<0 and i>=0){
        for(int ii = 0; ii<=i; ii++){
            if(s1[ii]!='*'){
                return false;
            }
        }
        return true;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]||s1[i]=='?'){
        return dp[i][j] = memor(i-1,j-1,s1,s2,dp);
    }

    if(s1[i]=='*'){
        return dp[i][j] = memor(i-1,j,s1,s2,dp) or memor(i,j-1,s1,s2,dp);
    }

    return dp[i][j]=false;
}

int main(){

    string s1, s2;
    cin>>s1>>s2;

    int n = s1.size();
    int m = s2.size();

    cout<<recurr(n-1,m-1,s1,s2)<<"\n";

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<memor(n-1,m-1,s1,s2,dp)<<"\n";

    // Tabulation
    vector<vector<bool>> dpp(n+1,vector<bool>(m+1,false));
    dpp[0][0] = true;
    for(int j = 1; j<=m; j++){
        dpp[0][j] = false;
    }

    for(int i = 1; i<=n; i++){
        bool flag = true;
        for(int ii = 1; ii<=i; ii++){
            if(s1[ii-1]!='*'){
                flag = false;
                break;
            }
        }
        dpp[i][0] = flag;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1] or s1[i-1]=='?'){
                dpp[i][j] = dpp[i-1][j-1];
            }
            else if(s1[i-1]=='*'){
                dpp[i][j] = dpp[i-1][j] or dpp[i][j-1];
            }
            else{
                dpp[i][j] = false;
            }
        }
    }

    cout<<dpp[n][m]<<"\n";


    return 0;
}