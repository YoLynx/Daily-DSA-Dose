// Here we will need to handle every node in the tree ourself.
// We will need to maintain a stack to keep track of the nodes we have seen.
// We will also need to maintain a vector to store the result.
// Since Stack is LIFO, we will first push the right child and then the left child.

class Solution {
public:

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            root=st.top();
            st.pop();
            res.push_back(root->val);

            if(root->right!=nullptr) st.push(root->right); //pehle right then left
            if(root->left!=nullptr) st.push(root->left);
        }
        return res;
    }
};