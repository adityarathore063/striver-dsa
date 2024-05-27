#include <bits/stdc++.h>
using namespace std;

int recurr(int i, int j, string s1, string s2, vector<vector<int>> dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s1[i] == s2[j])
    {
        return dp[i][j] = recurr(i - 1, j - 1, s1, s2, dp) + recurr(i - 1, j, s1, s2, dp);
    }

    return dp[i][j] = recurr(i - 1, j, s1, s2, dp);
}
int main()
{

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << recurr(n - 1, m - 1, s1, s2, dp) << "\n";

    vector<vector<int>> dpp(n+1,vector<int>(m+1,0));

    for(int i = 0; i<=n; i++){
        dpp[i][0] = 1;
    }
    for(int j = 1; j<=m; j++){
        dpp[0][j] = 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dpp[i][j] = dpp[i-1][j-1] + dpp[i-1][j];
            }
            else{
                dpp[i][j] = dpp[i-1][j];
            }
        }
    }
    cout<<dpp[n][m]<<"\n";

    return 0;
}