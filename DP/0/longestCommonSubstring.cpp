#include<bits/stdc++.h>
using namespace std;

int main(){

    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dpp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
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
                ans = max(ans,dpp[i][j]);
            }// if Not matches
            else{
                dpp[i][j] = 0;
            }
        }
    }

    cout<<ans<<"\n";


    return 0;
}