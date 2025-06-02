// Problem Link : https://leetcode.com/problems/reverse-integer/description/

// For getting the last digit we perform % 10 operation.
// For removing the last digit we perform / 10 operation.

/* Check if appending the digit to ans would cause overflow or underflow. This is done by comparing ans with INT_MAX / 10 and INT_MIN / 10.
If ans is greater than INT_MAX / 10, multiplying it by 10 and adding any digit would exceed INT_MAX.
Similarly, if ans is less than INT_MIN / 10, multiplying it by 10 and adding any digit would go below INT_MIN. */

class Solution {
public:
    int reverse(int x) {
        int rev=0;

        while(x!=0) {
            int ld=x%10;

            if((rev>INT_MAX/10) || (rev<INT_MIN/10)) return 0;

            rev=rev*10+ld;
            x=x/10;
        }
        return rev;
    }
};