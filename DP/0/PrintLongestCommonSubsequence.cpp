#include <bits/stdc++.h>
using namespace std;

int recur(int ind1, int ind2, string s1, string s2)
{

    if (ind1 < 0 or ind2 < 0)
    {
        return 0;
    }
    // If matches
    if (s1[ind1] == s2[ind2])
    {
        return (1 + recur(ind1 - 1, ind2 - 1, s1, s2));
    }

    // if Not matches

    return (max(recur(ind1 - 1, ind2, s1, s2), recur(ind1, ind2 - 1, s1, s2)));
}

int memor(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{

    if (ind1 < 0 or ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    // If matches
    if (s1[ind1] == s2[ind2])
    {
        return dp[ind1][ind2] = (1 + memor(ind1 - 1, ind2 - 1, s1, s2, dp));
    }

    // if Not matches

    return dp[ind1][ind2] = (max(memor(ind1 - 1, ind2, s1, s2, dp), memor(ind1, ind2 - 1, s1, s2, dp)));
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    cout << recur(n - 1, m - 1, s1, s2) << "\n";

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << memor(n - 1, m - 1, s1, s2, dp) << "\n";

    // Tabulation
    //  In base case for tabulation negative index is coming so we shifted the index in right direction by 1
    vector<vector<int>> dpp(n + 1, vector<int>(m + 1, 0));
    // base case
    for (int i = 0; i <= n; i++)
        dpp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dpp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // If matches
            if (s1[i-1] == s2[j-1])
            {
                dpp[i][j] = (1 + dpp[i-1][j-1]);
            }// if Not matches
            else{
                dpp[i][j] = max(dpp[i-1][j],dpp[i][j-1]);
            }
        }
    }
    int len = dpp[n][m];
    int index = len-1;
    // printing Longest common subsequence
    string s;
    for(int i = 0; i<len; i++){
        s+='$';
    }
    int i = n, j = m;
    while(i>0 and j>0){
        if(s1[i-1]==s2[j-1]){
            s[index] = s1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dpp[i-1][j]>dpp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<s<<"\n";

    return 0;
}