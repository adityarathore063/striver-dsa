#include<bits/stdc++.h>
using namespace std;

bool func(int i, string s){
    if(i>=(s.size()/2)){
        return true;
    }
    if(s[i]!=s[s.size()-1-i]){
        return false;
    }
    return func(i+1,s);

}
int main(){

    string s = "abdba";
    string str = "abgsh";
    cout<<func(0,s)<<"\n";
    cout<<func(0,str)<<"\n";

    return 0;
}