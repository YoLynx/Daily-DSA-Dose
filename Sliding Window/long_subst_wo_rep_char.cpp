// Naive or brute force approach : Generate all the substrings of the given string and check if they are unique or not. If they are unique, then check if their length is greater than the maximum length found so far. If it is, then update the maximum length.
// We make use of hash array to check if the characters are unique or not.
// Time complexity : O(n^2)

// Generates all the strings : O(n^2)

/* for (int i = 0; i < n; i++) {
    string sub = "";
    for (int j = i; j < n; j++) {
        sub = sub + s[j];
        // You can print or store 'sub' here
    }
}*/

// better approach : sliding window-variable size
// We can use a hash array to store the last index of each character.

// Time complexity : O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int l=0, r=0, res=0;

        while(r<s.size()) {
            if(hash[s[r]]!=-1) {
                if(hash[s[r]]>=l) {
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            res=max(res, len);
            hash[s[r]]=r;
            r++;
        }
        return res;
    }
};

