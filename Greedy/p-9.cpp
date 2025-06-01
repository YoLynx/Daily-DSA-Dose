// Problem Link : https://leetcode.com/problems/candy/description/
// God question.
// Get both left and right arrays, then take the maximum of both for each index.  


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n);
        vector<int> right(n);
        int res=0;
        left[0]=1;
        right[n-1]=1;

        for(int i=1;i<n;i++) {
            if(ratings[i]>ratings[i-1]) {
                left[i]=left[i-1]+1;
            }
            else left[i]=1;
        }

        for(int i=n-2;i>=0;i--) {
            if(ratings[i]>ratings[i+1]) {
                right[i]=right[i+1]+1;
            }
            else right[i]=1;
        }
        
        for(int i=0;i<n;i++) {
            res=res+max(left[i], right[i]);
        }
        return res;
    }
};