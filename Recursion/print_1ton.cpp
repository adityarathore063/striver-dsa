#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    func(i+1,n);
}
int main(){

    func(1,6);

    return 0;
}