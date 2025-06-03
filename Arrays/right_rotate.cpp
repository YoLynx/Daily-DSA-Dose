// Problem Link : https://leetcode.com/problems/rotate-array/

/*
--> reverse the entire array
--> reverse the first k elements
--> reverse remaining n-k elements
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};