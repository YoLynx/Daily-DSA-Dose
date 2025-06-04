// Problem Link : https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// Start iterating from the end of the array and keep track of the maximum element seen so far.


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> res;
        int max=arr[n-1];
        res.push_back(arr[n-1]);
        
        for(int i=n-2;i>=0;i--) {
            if(arr[i]>=max) {
                max=arr[i];
                res.push_back(arr[i]);
            }
        }
        // vector<int> ans;
        reverse(res.begin(), res.end());
        return res;
    }
};