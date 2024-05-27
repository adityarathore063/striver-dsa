#include<bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
};

bool comparator(struct meeting m1, meeting m2){
    if(m1.end<m2.end)return true;
    return false;
}
int meeting_oneRoom(int s[], int e[], int n){
    struct meeting meet[n];
    for(int i = 0; i<n; i++){
        meet[i].start = s[i];
        meet[i].end = e[i];
    }
    sort(meet,meet+n,comparator);
    int ans = 1;
    int end_limit = meet[0].end;

    for(int i = 1; i<n; i++){
        if(meet[i].start>end_limit){
            ans++;
            end_limit = meet[i].end;
        }
    }
    return ans;

}
int main(){

    int n;
    cin>>n;
    int s[n], e[n];
    for(int i = 0; i<n; i++){
        cin>>s[i]>>e[i];
    }
    cout<<meeting_oneRoom(s,e,n)<<"\n";

    return 0;
}