#include<bits/stdc++.h>
using namespace std;

void subseq(int ind, int arr[], int n, vector<int>&ds){
    if(ind==n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<"\n";
        return;
    }
    // take the element
    ds.push_back(arr[ind]);
    subseq(ind+1,arr,n,ds);
    // pop up for not take 
    ds.pop_back();
    // not taking the element
    subseq(ind+1,arr,n,ds);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>ds;
    subseq(0,arr,n,ds);
    return 0;
}