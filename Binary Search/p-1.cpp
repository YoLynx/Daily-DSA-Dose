// Problem Link : https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

// Most easy -- 
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        return upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);
    }
};


// Optimsed --

