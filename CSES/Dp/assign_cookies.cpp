// Problem Link - https://leetcode.com/problems/assign-cookies/
// Approach: Greedy
// Time Complexity: O(nlogn)
// Space Complexity: O(1)


class Solution {
  public:
      int findContentChildren(vector<int>& g, vector<int>& s) {
          int m=g.size();
          int n=s.size();
          int l=0, r=0;
          sort(g.begin(), g.end());
          sort(s.begin(), s.end());
  
          while(l<n && r<m) {
              if(g[r]<=s[l]) r++;
              l++;
          }
  
          return r;
      }
  };