// Problem link : https://leetcode.com/problems/same-tree/
// Just do any traversal and comapre the values of the nodes at each step.


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr || q==nullptr) return (p==q);
        return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};