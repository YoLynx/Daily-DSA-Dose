// Problem Link : https://leetcode.com/problems/isomorphic-strings/description/
// One-to-one mapping of characters in two strings.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        map<char, int> msp;
        map<char, int> mtp;

        for(int i=0;i<s.length();i++) {
            char sc=s[i];
            char tc=t[i];
            if(msp.count(sc) && msp[sc]!=tc) return false;

            if(mtp.count(tc) && mtp[tc]!=sc) return false;

            msp[sc]=tc;
            mtp[tc]=sc;
        }
        return true;
    }
};