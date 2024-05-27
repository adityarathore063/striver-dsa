#include<bits/stdc++.h>
using namespace std;

// Using Recursion
int maxSum(int ind, vector<int> &arr)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    int pick = arr[ind] + maxSum(ind - 2, arr);
    int notPick = 0 + maxSum(ind - 1, arr);

    return max(pick, notPick);
}

// Using Memorization
int maxSum1(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = arr[ind] + maxSum(ind - 2, arr);
    int notPick = 0 + maxSum(ind - 1, arr);

    return dp[ind] = max(pick, notPick);
}

int main(){

    // A thief needs to rob money in a street. The houses in the street are arranged in a circular manner.
    //  Therefore the first and the last house are adjacent to each other.The security system in the street
    //   is such that if adjacent houses are robbed, the police will get notified.

    // Given an array of integers “Arr” which represents money at each house, we need to return the maximum amount
    //  of money that the thief can rob without alerting the police.


    return 0;
}