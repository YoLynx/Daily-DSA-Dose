// Probelm Link - https://leetcode.com/problems/max-consecutive-ones-iii/
// Brute force approach : Generate all the subarrays and stop when the number of 0's in the subarray is greater than k.
// Time complexity : O(n^2)

// Sliding Window - Variable size
// Time complexity : O(n)
class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int l=0, r=0, res=0, z=0;
        while(r<a.size()) {
            if(a[r]==0) z++;

            while(z>k) {
                if(a[l]==0) z--;
                l++;
            }

            if(z<=k) {
                int len=r-l+1;
                res=max(res, len);
            }
            r++;
        }
        return res;
    }
};