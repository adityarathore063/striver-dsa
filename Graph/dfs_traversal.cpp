#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &ans, int i)
{
    visited[i] = true;
    ans.push_back(i);
    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            dfs(adj, visited, ans, it);
        }
    }
}
vector<int> dfsOfGraph(int n, vector<int> adj[])
{
    vector<bool> visited(n + 1, 0);
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, ans, i);
        }
    }

    return ans;
}
int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = dfsOfGraph(n, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}