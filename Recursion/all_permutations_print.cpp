// class Solution {
// public:

//     void f(vector<int>&ds, vector<int>&nums, vector<vector<int>>&ans, vector<int>&freq) {
//         if(ds.size()==nums.size()) {
//             ans.push_back(ds);
//             return;
//         }

//         for(int i=0;i<nums.size();i++) {
//             if(!freq[i]) {
//                 ds.push_back(nums[i]);
//                 freq[i]=1;
//                 f(ds, nums, ans, freq);
//                 freq[i]=0;
//                 ds.pop_back();
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         vector<int> freq(nums.size());
//         for(int i=0;i<freq.size();i++) freq[i]=0;
//         f(ds, nums, ans, freq);
//         return ans;
//     }
// };


// We are printing all the permutations of the given array.
// We are making the use of hash map where we will see what elements we will take.