// Problem Link : https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> outer={{}};
        // int n=nums.size();
        for(int it : nums) {
            int n=outer.size();
            for(int i=0;i<n;i++) {
                vector<int> inter=outer[i];
                inter.push_back(it);
                outer.push_back(inter);
            }
        }
        return outer;
    }
};