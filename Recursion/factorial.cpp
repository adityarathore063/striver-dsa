#include<bits/stdc++.h>
using namespace std;

int func(int n){
    if(n==1)return 1;
    return (n*func(n-1));
}
int main(){

    cout<<func(5)<<"\n";
    return 0;
}