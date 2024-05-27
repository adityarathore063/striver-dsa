#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
    if(i==0){
        return;
    }
    cout<<i<<" ";
    func(i-1,n);
}
int main(){

    func(6,6);

    return 0;
}