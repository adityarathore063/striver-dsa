#include<bits/stdc++.h>
using namespace std;

int func(int n){
    if(n==0 or n==1){
        return n;
    }
    return func(n-1)+func(n-2);
}
int main(){
    cout<<func(0)<<"\n";
    cout<<func(1)<<"\n";
    cout<<func(2)<<"\n";
    cout<<func(3)<<"\n";
    cout<<func(4)<<"\n";
    cout<<func(5)<<"\n";
    cout<<func(6)<<"\n";

    return 0;
}