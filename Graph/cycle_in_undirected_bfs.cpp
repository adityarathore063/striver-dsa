#include <bits/stdc++.h>
using namespace std;

bool cycle_bfs(vector<int> adj[], vector<int> &visited, int i)
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    visited[i] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (auto it : adj[i])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push({it, node});
            }
            else if (parent != it)
            {
                return true;
            }
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
            if (cycle_bfs(adj, visited, i))
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