// Problem Link : https://leetcode.com/problems/palindrome-number/description/


class Solution {
public:
    bool isPalindrome(int x) {
        long long rev=0;
        int dup=x;
        if(x<0) return false;
        while(x!=0) {
            int ld=x%10;

            rev=rev*10+ld;
            x=x/10;
        }

        if(dup==rev) return true;
        else return false;
    }
};