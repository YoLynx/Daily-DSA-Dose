// Problem Link : https://leetcode.com/problems/subarray-sum-equals-k/s

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map <int, int> mp;
        int ps=0, cnt=0;
        mp[0]=1;

        for(int i=0;i<n;i++) {
            ps+=nums[i];

            int rem=ps-k;
            cnt+=mp[rem];
            mp[ps]+=1;
            
        }
        return cnt;
    }
};