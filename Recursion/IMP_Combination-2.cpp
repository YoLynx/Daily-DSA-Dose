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


// Here the idea is that we sort the array and see from which we can start our ans arrays. suppose our array sorted is [1,1,1,2,2] We can only start with index-0 and index-3. So we will start with index-0 and then we will see if we can take the next element or not. If we can take the next element then we will take it otherwise we will not take it. We will keep on doing this until we reach the target. If we reach the target then we will push the ans array into the final ans array. If we reach the end of the array then we will return. This is how we will solve this problem.