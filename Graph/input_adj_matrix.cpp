#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n+1][n+1];
    for(int i = 1; i<=n;  i++){
        int u, v;
        cin>>u>>v;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }

    return 0;
}