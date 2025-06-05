// Problem Link : https://leetcode.com/problems/rotate-string/
// s+s gives all possible rotations of s.


class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        return (s+s).find(goal) != string::npos;
    }
};