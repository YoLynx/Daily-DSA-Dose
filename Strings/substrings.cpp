// Problem Link : https://www.geeksforgeeks.org/problems/count-the-substrings--141634/1

// User function Template for C++
class Solution {
  public:
    int countSubstring(string S) {
        // code here
        map<int, int> mp;
        mp[0]=1;
        int res=0;
        int sum=0;
        
        for(char c:S) {
            int val;
            if(isupper(c)) val=1;
            else val=-1;
            
            sum+=val;
            if(mp.find(sum)!=mp.end()) res+=mp[sum];
            mp[sum]++;
        }
        return res;
    }
};