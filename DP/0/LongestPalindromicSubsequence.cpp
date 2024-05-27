#include<bits/stdc++.h>
using namespace std;

int main(){

    string s1, s2;
    cin >> s1;
    int n = s1.size();
    int m = s1.size();
    s2 = s1;
    reverse(s2.begin(),s2.end());

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

    cout<<dpp[n][m]<<"\n";


    return 0;
}