// Problem Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// We maintain a queue to traverse the tree level by level. We also maintain a flag to determine the direction of traversal for each level (left to right or right to left). For each node, we insert its value into the result vector at the appropriate index based on the current direction. After processing all nodes at a level, we toggle the direction for the next level.



class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);
        int flag=1;   // L -> R

        while(!q.empty()) {
            int size=q.size();
            vector<int> v(size);

            for(int i=0;i<size;i++) {
                TreeNode* node=q.front();
                q.pop();

                int index=(flag) ? i : (size-1-i);
                v[index]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag=!flag;
            res.push_back(v);
        }
        return res;
    }
};