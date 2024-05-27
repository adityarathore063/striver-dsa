#include <bits/stdc++.h>
using namespace std;
void comb_sum2(int ind, int arr[], int n, int sum, vector<int> &ds)
{
    if (sum == 0)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if (i > ind and arr[i] == arr[i - 1])
            continue;
        if (arr[i] > sum)
            break;
        ds.push_back(arr[i]);
        comb_sum2(i + 1, arr, n, sum - arr[i], ds);
        ds.pop_back();
    }
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
    sort(arr, arr + n);
    comb_sum2(0, arr, n, sum, ds);
    return 0;
}