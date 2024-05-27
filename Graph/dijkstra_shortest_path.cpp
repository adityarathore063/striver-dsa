#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, m, src;
    cin>>n>>m>>src;

    vector<pair<int,int>> adj[n+1];

    int u, v, wt;
    for(int i = 0; i<m; i++){
        cin>>u>>v>>wt;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // Min heap
    vector<int>dist(n+1,INT_MAX);
    dist[src] = 0;

    pq.push(make_pair(0,src)); // (dist,from)

    while(!pq.empty()){
        int dis = pq.top().first;
        int prev = pq.top().second;

        pq.pop();

        for(auto it : adj[prev]){
            int nextnode = it.first;
            int nextdist = it.second;

            if(dist[nextnode]>dist[prev]+nextdist){
                dist[nextnode]=dist[prev]+nextdist;
                pq.push(make_pair(dist[nextnode],nextnode));
            }
        }
    }

    for(int i = 1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<"\n";

    return 0;
}