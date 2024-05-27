#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int u, v;

        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    return 0;
}