#include<bits/stdc++.h>
using namespace std;

struct Item
{
    /* data */
    int value;
    int weight;
};

bool comparator(Item a, Item b){
    double ratio1 = double(a.value)/double(a.weight);
    double ratio2 = double(b.value)/double(b.weight);

    return ratio1>ratio2;
}
double fractional_knap(int w, int n, Item arr[]){

    sort(arr,arr+n,comparator);

    double ans = 0.0;
    int currWeight = 0;
    for(int i = 0; i<n; i++){
        if(currWeight + arr[i].weight <= w){
            currWeight = currWeight + arr[i].weight;
            ans+=arr[i].value;
        }
        else{
            int remaining_weight = w - currWeight;
            ans += (arr[i].value/double(arr[i].weight)) * double(remaining_weight);
            break;
        }
    }

    return ans;
}
int main(){

    int n,wt;
    cin>>n>>wt;

    Item arr[n];
    for(int i = 0; i<n; i++){
        int v,w;
        cin>>v>>w;
        arr[i].value = v;
        arr[i].weight = w;
    }
    cout<<fixed<<setprecision(2)<<fractional_knap(wt,n,arr)<<"\n";
    return 0;
}