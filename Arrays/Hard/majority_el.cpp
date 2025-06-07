// Problem Link : https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()==1) return {nums[0]};
        vector<int> ans;
        map<int, int> mp;

        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        int lim=nums.size()/3;

        for(auto it : mp) {
            int el=it.first;
            int freq=it.second;

            if(freq>lim) ans.push_back(el);
        }
        return ans;
    }
};