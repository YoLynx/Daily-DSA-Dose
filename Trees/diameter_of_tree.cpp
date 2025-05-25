// Problem link : https://leetcode.com/problems/diameter-of-binary-tree/
// Calculate the height of the left and right subtrees, and update the diameter at each node.

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        height(root, d);
        return d;
    }
    
    int height(TreeNode* node, int& d) {
        if(node==nullptr) return 0;
        int lh=height(node->left, d);
        int rh=height(node->right, d);

        d=max(d, lh+rh);
        return 1+max(lh, rh);
    }

};