#include <bits/stdc++.h>
using namespace std;

bool cycle_dfs(vector<int> adj[], int visited[], int node, int dfsvis[])
{
    visited[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (cycle_dfs(adj, visited, it, dfsvis))
            {
                return true;
            }
        }
        else if (dfsvis[it])
        {
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}
bool check_cycle(vector<int> adj[], int n)
{
    int visited[n], dfsvis[n];
    memset(visited, 0, sizeof visited);
    memset(dfsvis, 0, sizeof dfsvis);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (cycle_dfs(adj, visited, i, dfsvis))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (check_cycle(adj, n))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}