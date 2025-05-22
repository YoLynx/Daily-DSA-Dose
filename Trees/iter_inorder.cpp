/*We go to the leftmost node until null is encountered and then we start popping the nodes from the stack and 
then go to the right child of the popped node.*/

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* node=root;

        stack<TreeNode*> st;
        while(true) {
            if(node!=nullptr) {
                st.push(node);
                node=node->left;
            }
            else {
                if(st.empty()==true) break;
                node=st.top();
                st.pop();
                res.push_back(node->val);
                node=node->right;
            }
        }
        return res;
    }
};