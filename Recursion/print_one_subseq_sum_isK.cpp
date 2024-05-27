#include <bits/stdc++.h>
using namespace std;

bool subseq(int ind, int arr[], int n, vector<int> &ds, int sum)
{
    if (ind == n)
    {
        if (sum == 0)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << "\n";
            return true;
        }
        else return false;
        
    }
    // take the element
    ds.push_back(arr[ind]);
    sum -= arr[ind];
    if(subseq(ind + 1, arr, n, ds, sum))return true;
    // pop up for not take
    ds.pop_back();
    sum += arr[ind];
    // not taking the element
    if(subseq(ind + 1, arr, n, ds, sum)) return true;
    return false;
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ds;
    subseq(0, arr, n, ds, sum);
    return 0;
}