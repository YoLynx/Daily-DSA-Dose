// level : medium 
// link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/1642147503/


class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int lsum=0, rsum=0, res=0;
        if(k>a.size()) return 0;
        for(int i=0;i<k;i++) lsum+=a[i];
        res=lsum;
        int ri=a.size()-1;

        for(int i=k-1;i>=0;i--) {
            lsum=lsum-a[i];
            rsum+=a[ri];
            ri--;
            res=max(res, lsum+rsum);
        }
        return res;
    }
};