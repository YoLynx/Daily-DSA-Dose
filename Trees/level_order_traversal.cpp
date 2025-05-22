// We maintain a queue to keep track of the nodes at the current level.
// We have initialized the queue with the root node.
// We also have initialized a vector of vector to store the result.
// And in that vector we will store the nodes at each level as a vector.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> qq;
        qq.push(root);

        while(!qq.empty()) {
            vector<int> level;
            int size=qq.size();
            for(int i=0;i<size;i++) {
                TreeNode* node=qq.front();
                qq.pop();
                level.push_back(node->val);
                
                if(node->left!=nullptr) qq.push(node->left);
                if(node->right!=nullptr) qq.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};