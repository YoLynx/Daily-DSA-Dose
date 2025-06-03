// Problem Link : https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=1;          // loop goes from 1 to n-2 as we have handled the edge cases.
        int high=n-2;
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        while(low<=high) {
            int mid=(low+high)/2;
            // mid element is single.
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];

            if(mid%2==0 && nums[mid]==nums[mid+1] || mid%2==1 && nums[mid]==nums[mid-1]) {
                low=mid+1;       // eliminate the left half. 
            }
            else high=mid-1;     // eliminate the right half.
        }
        return -1;
    }
};