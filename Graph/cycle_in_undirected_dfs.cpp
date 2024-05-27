#include <bits/stdc++.h>
using namespace std;

bool cycle_dfs(vector<int> adj[], vector<int> &visited, int node, int parent)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (cycle_dfs(adj, visited, it, node))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}
bool check_cycle(vector<int> adj[], int n)
{
    vector<int> visited(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (cycle_dfs(adj, visited, i, -1))
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