#include<bits/stdc++.h>
using namespace std;

bool toposort(int n, vector<int> adj[]){
    queue<int>q;
    vector<int> indegree(n,0);

    for(int i = 0; i<n; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    for(int i = 0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }

    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(count==n){
        return false;
    }
    else{
        return true;
    }
}
int main(){

    int n, m;
    cin>>n>>m;

    vector<int> adj[n];
    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);

    }
    cout<<toposort(n,adj)<<"\n";
    return 0;
}