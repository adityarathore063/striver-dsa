#include<bits/stdc++.h>
using namespace std;

void func(int i, int n, int sum){
    
    if(i>n){
        cout<<sum<<"\n";
        return;
    }
    sum+=i;
    func(i+1,n,sum);
}
int func1(int n){
    if(n<=1){
        return n;
    }
    return n+func1(n-1);
}
int main(){

    func(1,5,0);
    cout<<func1(5)<<"\n";

    return 0;
}