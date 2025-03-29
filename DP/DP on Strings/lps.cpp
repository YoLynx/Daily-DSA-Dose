// Problem - Longest Palindromic Subsequence
// Problem Link - https://leetcode.com/problems/longest-palindromic-subsequence/
// Tabulation - O(n*m) | Time - O(n*m) | Space - O(n*m)

// Approach - Reverse the given string, store and apply the same logic of LCS.

class Solution {
  public:
      int longestPalindromeSubseq(string s) {
          string t=s;
          reverse(t.begin(), t.end());
  
          int n=s.size();
          int m=t.size();
  
          vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
          for(int i=0;i<=n;i++) dp[i][0]=0;
          for(int j=0;j<=m;j++) dp[0][j]=0;
  
          for(int i=1;i<=n;i++) {
              for(int j=1;j<=m;j++) {
                  if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                  else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);                
              }
          }
          return dp[n][m];
      }
  };


