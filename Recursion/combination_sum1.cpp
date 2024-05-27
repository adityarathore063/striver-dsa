#include <bits/stdc++.h>
using namespace std;
void comb_sum1(int ind, int arr[], int n, int sum, vector<int> &ds)
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
        }
        return;
    }
    if (arr[ind] <= sum)
    {
        ds.push_back(arr[ind]);
        comb_sum1(ind, arr, n, sum - arr[ind], ds);
        ds.pop_back();
    }
    comb_sum1(ind + 1, arr, n, sum, ds);
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
    comb_sum1(0, arr, n, sum, ds);
    return 0;
}