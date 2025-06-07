// Problem Link : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        int hash[n+1] = {0};
        
        for(int i=0;i<n;i++) hash[arr[i]]++;
        int rep=-1, mis=-1;
        
        for(int i=1;i<=n;i++) {
            if(hash[i]==2) rep=i;
            else if(hash[i]==0) mis=i;
            
            if(rep!=-1 && mis!=-1) break;
        }
        return {rep, mis};
    }
};