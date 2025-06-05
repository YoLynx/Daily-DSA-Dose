// Problem Link : https://leetcode.com/problems/largest-odd-number-in-string/

class Solution {
public:
    string largestOddNumber(string num) {
        if(num.back()%2==1) return num;
        
        for(int i=num.length()-1;i>=0;i--) {
            if(num[i]%2==1) return num.substr(0, i+1);
        }
        return "";
    }
};