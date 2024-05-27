#include <bits/stdc++.h>
using namespace std;

bool bipartite_bfs(vector<int> adj[], int color[], int node)
{
    queue<int> q;
    q.push(node);
    color[node] = 1;

    while (!q.empty())
    {
        int src = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool check_biparitite(vector<int> adj[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);

    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartite_bfs(adj, color, i))
            {
                return false;
            }
        }
    }
    return true;
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

    if (check_biparitite(adj, n))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}