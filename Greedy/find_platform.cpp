#include<bits/stdc++.h>
using namespace std;

int min_platform(int arr[], int dep[], int n){
    sort(arr,arr+n);
    sort(dep,dep+n);

    int ans = 1, platform_needed = 1;
    int i = 1;
    int j = 0;
     while(i<n and j<n){
         if(arr[i]<=dep[j]){
             platform_needed++;
             i++;
         }
         else if(arr[i] > dep[j]){
             platform_needed--;
             j++;
         }

         if(platform_needed>ans){
             ans = platform_needed;
         }
     }
     return ans;
}

int main(){

    int n;
    cin>>n;
    int arr[n], dep[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i]>>dep[i];
    }
    cout<<min_platform(arr,dep,n)<<"\n";
    return 0;

}