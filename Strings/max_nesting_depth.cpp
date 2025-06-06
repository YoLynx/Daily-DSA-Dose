// Problem Link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                cnt++;
                ans=max(ans, cnt);
            }
            else if(s[i]==')') cnt--;
        }
        return ans;
    }
};