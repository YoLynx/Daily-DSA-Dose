// Problem Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// we check for sorted halves and the first elements will be the smallest, we take minimum of em.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;

        while(low<=high) {
            int mid=(low+high)/2;

            if(nums[low]<=nums[mid]) {          // left half sorted
                ans=min(ans, nums[low]);
                low=mid+1;
            }

            else {
                ans=min(ans, nums[mid]);       // right half sorted
                high=mid-1;
            }
        }
        return ans;
    }
};