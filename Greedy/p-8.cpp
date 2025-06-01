// Problem Link : https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Good question.

class Solution {
  public:

    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int n=arr.size();
        int i=0, j=0, cnt=0;
        int res=0;
        while(i<n) {
            //int res=0;
            if(arr[i]<=dep[j]) {
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            res=max(res, cnt);
        }
        return res;
    }
};