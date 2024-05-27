#include<bits/stdc++.h>
using namespace std;

void recurpermute(vector<int> &ds, vector<int> &nums, vector<vector<int>>&ans, int freq[]){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i<nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurpermute(ds,nums,ans,freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for(int i = 0; i<nums.size(); i++) freq[i] = 0;
    recurpermute(ds,nums,ans,freq);
    return ans;
}

void recurpermute2(int ind, vector<int> &nums, vector<vector<int>> &ans){
    if(ind==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = ind; i<nums.size(); i++){
        swap(nums[ind],nums[i]);
        recurpermute2(ind+1,nums,ans);
        swap(nums[ind],nums[i]);
    }
}
vector<vector<int>> permute2(vector<int> &nums){
    vector<vector<int>> ans;
    recurpermute2(0,nums,ans);
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

    vector<vector<int>> ans = permute(vec);
    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"\n";
    vector<vector<int>> ans2 = permute2(vec);
    for(int i = 0; i<ans2.size(); i++){
        for(int j = 0; j<ans2[i].size(); j++){
            cout<<ans2[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}