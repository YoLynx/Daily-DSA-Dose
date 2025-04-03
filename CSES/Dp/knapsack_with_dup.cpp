// Problem Link - https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution {
  public:
  
    int solve(int ind, vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>>& dp) {
        
        if(ind==0) {
            return (wt[0]<=capacity) ? (capacity/wt[0])*val[0] : 0;
        }
        if(dp[ind][capacity]!=-1) return dp[ind][capacity];
        
        int notpick=solve(ind-1, val, wt, capacity, dp);
        int pick=INT_MIN;
        
        if(wt[ind]<=capacity) pick=val[ind]+solve(ind, val, wt, capacity-wt[ind], dp);
        
        return dp[ind][capacity]=max(pick, notpick);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return solve(n-1, val, wt, capacity, dp);
    }
};