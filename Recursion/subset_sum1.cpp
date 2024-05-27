#include<bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int>&nums, int n, vector<int>&ans){
    if(ind==n){
        ans.push_back(sum);
        return;
    }
    func(ind+1,sum+nums[ind],nums,n,ans);

    func(ind+1,sum,nums,n,ans);
}
vector<int> subsetSum(vector<int>&nums, int n){
    vector<int>ans;
    func(0,0,nums,n,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){

    int n;
    cin>>n;
    vector<int>vec;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        vec.push_back(ele);
    }

    vector<int> ans = subsetSum(vec,n);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}