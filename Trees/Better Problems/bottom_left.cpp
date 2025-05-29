// Problem link : https://leetcode.com/problems/bottom-left-tree-value/
// We maintain a queue and traverse the tree level by level, always pushing the right child before the left child. This way, when we reach the last level, the first node we encounter will be the leftmost node of that level.

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int ans;

        q.push(root);

        while(!q.empty()) {
            TreeNode* node=q.front();
            q.pop();

            ans=node->val;
            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
        return ans;
    }
};