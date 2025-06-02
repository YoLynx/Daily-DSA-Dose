// Problem Link : https://takeuforward.org/data-structure/find-gcd-of-two-numbers/

/* 
To find the GCD of n1 and n2 where n1 > n2:
-- Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
-- Once one of them becomes 0, the other number is the GCD of the original numbers. 
*/

class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        while(a>0 && b>0) {
            if(a>b) a=a%b;
            else b=b%a;
        }
        if(a==0) return b;
        else return a;
    }
};