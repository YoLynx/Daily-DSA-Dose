// Problem link : https://leetcode.com/problems/count-complete-tree-nodes/
// We compare the heights of the left and right subtrees. If they are equal, it means the tree is a complete binary tree, and we can use the formula (1 << height) - 1 to calculate the number of nodes. If they are not equal, we recursively count the nodes in the left and right subtrees.

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh=leftheight(root);
        int rh=rightheight(root);

        if(lh==rh) return (1<<lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int leftheight(TreeNode* node)  {
        long long h=0;
        while(node) {
            h++;
            node=node->left;
        }
        return h;
    }

    int rightheight(TreeNode* node)  {
        long long h=0;
        while(node) {
            h++;
            node=node->right;
        }
        return h;
    }
};