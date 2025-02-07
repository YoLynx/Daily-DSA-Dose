// class Solution {
// public:
//     void f(int i, int target, vector<vector<int>>&ans, vector<int>&a, vector<int>&ds) {
//         if(target==0) {
//             ans.push_back(ds);
//             return;
//         }
//         for(int j=i;j<a.size();j++) {
//             if(j>i && a[j]==a[j-1]) continue;
//             if(a[j]>target) break;
//             ds.push_back(a[j]);
//             f(j+1, target-a[j], ans, a, ds);
//             ds.pop_back();
//         }
//     }

// public :
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> ans;
//         vector<int> ds;
//         f(0, target, ans, candidates, ds);
//         return ans;
//     }
// };

// The idea here is to generate an array having subset sum. eg- [1,2,3] => [0,1,2,3,1,2,3,3,4,5,6] which contains 2^n elements. 
// If element must not repeat then we need to see that from which element we start.. just like Combination-2 problem
// Time Complexity -> O(2^n)+O(2^Nlog(2^N)). 
// Space Complexity -> O(2^n).
