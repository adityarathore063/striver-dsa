#include<bits/stdc++.h>
using namespace std;

int min_coins(vector<int>coins, int amount){
    sort(coins.begin(),coins.end(),greater<int>());
    int ans = 0;
    for(int i = 0; i<coins.size(); i++){
        if(coins[i]<=amount){
            ans = ans + (amount/coins[i]);
            amount = amount % coins[i];
        }
        if(amount==0){
            return ans;
        }
    }
    return -1;
}
int main(){

    int n;

    vector<int>coins;
    int amount;

    cin>>n>>amount;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        coins.push_back(ele);
    }

    cout<<min_coins(coins,amount)<<"\n";

    return 0;
}