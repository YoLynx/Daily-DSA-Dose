// problem link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

class Solution {
public:
    int ts=0;
    int sumRootToLeaf(TreeNode* root) {
        if(root==nullptr) return 0;

        help(root, 0);
        return ts;
    }

    void help(TreeNode* root, int cs) {
        if(root==nullptr) return;

        cs=cs+root->val;
        if(root->left==nullptr && root->right==nullptr) {
            ts+=cs;
            return;
        }
        help(root->left, cs*2);
        help(root->right, cs*2);
    }
};