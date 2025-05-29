class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;

        if(root->left==nullptr && root->right==nullptr) return 1;

        int ld=root->left==nullptr ? INT_MAX : minDepth(root->left);
        int rd=root->right==nullptr ? INT_MAX : minDepth(root->right);

        return 1+min(ld, rd);
    }
};