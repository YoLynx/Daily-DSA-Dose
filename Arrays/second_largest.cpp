// Problem Link : https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int large=INT_MIN;
        int slarge=INT_MIN;
        
        if(arr.size()<2) return -1;
        
        for(int i=0;i<arr.size();i++) {
            if(arr[i]>large) {
                slarge=large;
                large=arr[i];
            }
            else if(arr[i]>slarge && arr[i]!=large) slarge=arr[i];
        }
        return (slarge==INT_MIN) ? -1 : slarge;
    }
};