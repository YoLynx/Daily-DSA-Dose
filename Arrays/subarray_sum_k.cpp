// Problem Link : https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// Important question

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int, int> mp;     // hashmap
        int sum=0, res=0;
        
        for(int i=0;i<arr.size();i++) {
            sum+=arr[i];
            
            if(sum==k) {
                res=max(res, i+1);
            }
            
            int rem=sum-k;
            
            if(mp.find(rem)!=mp.end()) {
                int len=i-mp[rem];
                res=max(res, len);
            }
            
            if(mp.find(sum)==mp.end()) {
                mp[sum]=i;
            }
        }
        return res;
    }
};