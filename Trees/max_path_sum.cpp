// Problem Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/\
// Brute force : We take every possible pair of nodes and calculate the path sum between them, keeping track of the maximum sum found.
// This approach is inefficient as it has a time complexity of O(n^2) where n is the number of nodes in the tree.

// Better appraoch : For every node, we calculate the maximum path sum that can be formed by including that node and either of its left or right subtrees. The maximum path sum for the entire tree is then the maximum of these values.
// Time Complexity : O(n) where n is the number of nodes in the tree.

class Solution {
public:

    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root, maxi);
        return maxi;
    }

    int solve(TreeNode* node, int &maxi) {
        if(node==nullptr) return 0;

        int lh=max(0, solve(node->left, maxi));
        int rh=max(0, solve(node->right, maxi));
        maxi=max(maxi, node->val+lh+rh);

        return node->val+max(lh, rh);
    }
};