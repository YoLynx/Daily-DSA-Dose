// Problem link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Brute force : We build a root to node array of both and return the last element where they both have matching nodes.
// Better approach :

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q) return root;

        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);

        if(left==nullptr) return right;

        else if(right==nullptr) return left;

        else return root;
    }
};