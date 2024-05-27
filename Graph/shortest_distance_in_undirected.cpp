#include<bits/stdc++.h>
using namespace std;

void shortestBfs(int n,int src, vector<int> adj[]){
    int dist[n];
    for(int i = 0; i<n; i++){
        dist[i] = INT_MAX;
    }
    queue<int>q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
            if(dist[node] + 1< dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";

}
int main(){

    int n, m,src;
    cin>>n>>m>>src;

    vector<int> adj[n];
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    shortestBfs(n,src,adj);
    return 0;
}