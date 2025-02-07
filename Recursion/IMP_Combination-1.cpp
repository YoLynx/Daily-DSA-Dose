// class Solution {
// public:
//     void f(int i, int target, vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds) {
//         if(i==arr.size()) {
//             if(target==0) {    //base case
//                 ans.push_back(ds);
//             }
//             return;
//         }
//         // We pick the element
//         if(arr[i]<=target) {
//             ds.push_back(arr[i]);
//             f(i, target-arr[i],arr, ans, ds);
//             ds.pop_back();
//         }

//         // We do not pick the element
//         f(i+1, target, arr, ans, ds);
        
//     }

// public :
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         f(0, target, candidates, ans, ds);
//         return ans;
//     }
// };

// This idea is based on picking the element or not.
// This is basic code idea where the elements in the candidates array may repeat to make up the target sum.
// Time Complexity -> O(2^t.k) -> nearly exponential.  As we get 2^t subsequences.  Or 2^t*k is the time complexity as we are printing the subsequence.