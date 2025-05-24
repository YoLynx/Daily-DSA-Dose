// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Sliding Window Maximum Subarray Sum
// Given an array of integers Arr of size N and an integer K. Return the maximum sum of a subarray of size K.

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        
        int start=0, end=0;
        int sum=0;
        int res=0;
        while(end<arr.size()) {
            sum+=arr[end];
            
            if(end-start+1<k) end++;
            else if(end-start+1==k) {
                res=max(res, sum);
                sum-=arr[start];
                start++;
                end++;
            }
        }
        return res;
    }
};