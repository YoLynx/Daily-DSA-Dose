// class Solution {
//   public:
//       vector<vector<string>> partition(string s) {
//           vector<vector<string>> res;
//           vector<string> path;
//           f(0, s, res, path);
//           return res;
//       }
  
//       void f(int ind, string s, vector<vector<string>>&res, vector<string>&path) {
//           if(ind==s.size()) {
//               res.push_back(path);
//               return;
//           }
  
//           for(int i=ind;i<s.size();i++) {
//               if(isPalindrome(s, ind, i)) {
//                   path.push_back(s.substr(ind, i-ind+1));
//                   f(i+1, s, res, path);
//                   path.pop_back();
//               }
//           }
//       }
  
  
//       bool isPalindrome(string s, int start, int end) {
//           while(start<=end) {
//               if(s[start++]!=s[end--]) {
//                   return false;
//               }
//           }
//           return true;
//       }
  
  
  
//   };
  

// We are given a string and we have to partition the string in such a way that all the partitions are palindrome.
// We are using backtracking to solve this problem.
// So we try to put partitions on the string and check if the partition is palindrome or not.
// Suppose the string is aabb, so we put first partition on index 1, so we have a|abb, so we check if a is palindrome or not, so it is palindrome, so we move to next partition.
// So we put partition on index 2, so we have a|a|bb, so we check if a is palindrome or not, so it is palindrome, so we move to next partition.
// So on..., and base case is when we reach the end of the string, we push the path into the result.

// Time Complexity -> O(n * 2^n) and Space Complexity -> O(n * 2^n).