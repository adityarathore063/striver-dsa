#include <bits/stdc++.h>
using namespace std;

void toposort_dfs(vector<int> adj[], stack<int> &st, vector<int> &visited, int i)
{
    visited[i] = 1;
    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            toposort_dfs(adj, st, visited, it);
        }
    }
    st.push(i);
}
vector<int> toposort(int n, vector<int> adj[])
{
    vector<int> visited(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (visited[i]==0)
        {
            toposort_dfs(adj, st, visited, i);
        }
    }
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = toposort(n, adj);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}