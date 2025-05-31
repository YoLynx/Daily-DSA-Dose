// Problem Link : https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int cf=0, cte=0;
        for(int i=0;i<n;i++) {
            if(bills[i]==5) cf++;

            else if(bills[i]==10) {
                if(cf==0) return false;
                cf--;
                cte++;
            } 

            else {
                if(cf>0 && cte>0) {
                    cf--;
                    cte--;
                }
                else if(cf>=3) cf-=3;
                else return false;
            }
        }
        return true;
    }
};