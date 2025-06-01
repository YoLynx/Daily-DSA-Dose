// Problem LInk : https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxin=0;
        for(int i=0;i<nums.size();i++) {
            if(i>maxin) return false;
            maxin=max(maxin, i+nums[i]);
        }
        return true;
    }
};