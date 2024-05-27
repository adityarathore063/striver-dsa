#include<bits/stdc++.h>
using namespace std;

void func(int i, int n, int arr[]){
    if(i>=n/2){
        return;
    }
    swap(arr[i],arr[n-i-1]);
    func(i+1,n,arr);

}
int main(){

    int arr[] = {1, 2, 3, 4, 5};
    func(0,5,arr);
    for(int i = 0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}