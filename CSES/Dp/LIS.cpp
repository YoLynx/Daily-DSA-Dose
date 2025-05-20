// Problem: Longest Increasing Subsequence
// CSES Link - https://cses.fi/problemset/task/1145

#include <bits/stdc++.h>
//#define all(s) s.begin(), s.end()
using namespace std;
using ll=long long;
using ull=unsigned long long;

const int _N=1e5+5;

int solve(int ind, int prev, vector<int>& nums, vector<int>& dp) {
    if(ind==nums.size()) return 0;
    if(dp[prev+1]!=-1) return dp[prev + 1];

    int len=0+solve(ind + 1, prev, nums, dp);
    if(prev==-1 || nums[ind]>nums[prev]) {
        len=max(len, 1+solve(ind + 1, ind, nums, dp));
    }
    return dp[prev+1]=len;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    vector<int> dp(n+1, -1);
    cout<<solve(0, -1, nums, dp)<<endl;

    return 0;
}





