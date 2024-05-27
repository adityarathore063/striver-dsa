#include <bits/stdc++.h>
using namespace std;

int count_subseq(int ind, int arr[], int n, int sum){
    if(ind==n){
        if(sum==0){
            return 1;
        }
        return 0;
    }
    return count_subseq(ind+1,arr,n,sum-arr[ind])+count_subseq(ind+1,arr,n,sum);
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<count_subseq(0,arr,n,sum)<<"\n";    
    return 0;
}