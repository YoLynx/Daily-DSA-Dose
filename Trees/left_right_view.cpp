// Problem link : https://leetcode.com/problems/binary-tree-right-side-view/

// For Right Side view of binary tree, last node of every level is required. Therefore, we apply preorder but in reverse like Root, Right, Left.
// For the left side view, we would apply preorder in the normal way like Root, Left, Right.

class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        recursion(root, 0, res);
        return res;
    }

    void recursion(TreeNode* root, int level, vector<int>& res) {
        if(root==nullptr) return;

        if(level==res.size()) res.push_back(root->val);
        recursion(root->right, level+1, res);       // root->left for LEFT view
        recursion(root->left, level+1, res);        // root->right for LEFT view
        // Note: The order of recursion is important for right side view.
    }
};



// Iterative approach using queue
vector<int> rightView(Node *root){
        vector<int> res;
        if(root==NULL) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *temp = q.front();
            res.push_back(temp->data);
            int size = q.size();
            for(int i=0;i<size;i++){
                Node *curr = q.front();
                q.pop();
                if(curr->right!=NULL) q.push(curr->right);
                if(curr->left!=NULL) q.push(curr->left);
            }
        }
        return res;
    }