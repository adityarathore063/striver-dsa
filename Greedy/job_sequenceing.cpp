#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;

};

bool comparator(Job a, Job b){
    return a.profit>b.profit;
}

pair<int,int> job_sequencing(Job arr[],int n){
    sort(arr,arr+n,comparator);

    int maxi = arr[0].deadline;
    for(int i = 0; i<n; i++){
        maxi = max(maxi,arr[i].deadline);
    }
    int slot[maxi+1];
    for(int i = 0; i<=maxi; i++){
        slot[i] = -1;
    }

    int countJobs = 0, jobprofit = 0;
    for(int i = 0; i<n; i++){
        for(int j = arr[i].deadline; j>0; j--){
            if(slot[j]==-1){
                countJobs++;
                jobprofit+=arr[i].profit;
                slot[j] = i;
                break;
            }
        }
    }
    return make_pair(countJobs,jobprofit);
}
int main(){

    int n;
    cin>>n;
    Job arr[n];
    for(int i = 0; i<n; i++){
        int x,y,z;
        cin>>x>>y>>z;
        arr[i].id = x;
        arr[i].deadline = y;
        arr[i].profit = z;
    }

    pair<int,int> p = job_sequencing(arr,n);
    cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}