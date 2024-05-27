#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                ans.push_back(node);

                for (auto it : adj[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
    }
    return ans;
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

    vector<int> ans = bfs(adj, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}