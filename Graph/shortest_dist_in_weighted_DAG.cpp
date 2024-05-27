#include<bits/stdc++.h>
using namespace std;

void topoSort(stack<int> &st, int visited[], int node, vector<pair<int,int>> adj[]){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(!visited[it.first]){
            topoSort(st,visited,it.first,adj);
        }
    }
    st.push(node);
}

void shortestPath(int n, int src, vector<pair<int,int>> adj[]){
    int visited[n] = {0};
    stack<int>st;

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            topoSort(st,visited,i,adj);
        }
    }

    int dist[n];
    for(int i = 0; i<n; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node]!=INT_MAX){
            for(auto it : adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        if(dist[i]==INT_MAX){
            cout<<"INF ";
        }
        else{
            cout<<dist[i]<<" ";
        }
    }
    cout<<"\n";
}
int main(){

    int n, m, src;
    cin>>n>>m>>src;

    vector<pair<int,int>> adj[n];

    for(int i = 0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));

    }

    shortestPath(n,src,adj);
    return 0;
}