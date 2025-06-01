// Problem Link : https://leetcode.com/problems/jump-game-ii/
// When recursion is not allowed, we can use greedy approach to solve this problem.
// We consider the range of indices we can reach with the current number of jumps.

class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0, r=0, jumps=0;

        while(r<nums.size()-1) {
            int farthest=0;
            for(int i=l;i<=r;i++) {
                farthest=max(farthest, i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};