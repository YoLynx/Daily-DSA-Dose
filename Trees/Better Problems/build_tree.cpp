// Problem link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Given preorder and inorder traversal of a tree, construct the binary tree.
// The idea is to use a map to store the indices of inorder elements for quick access.

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmp;

        for(int i=0;i<inorder.size();i++) {
            inmp[inorder[i]]=i;
        }

        TreeNode* root=help(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmp);
        return root;
    }

    TreeNode* help(vector<int>& preorder,int pstart,int pend, vector<int>& inorder,int istart, int iend, map<int, int>& inmp) {
        if(pstart>pend || istart>iend)  return nullptr;

        TreeNode* root=new TreeNode(preorder[pstart]);

        int inroot=inmp[root->val];
        int node_left=inroot-istart;

        root->left=help(preorder, pstart+1, pstart+node_left, inorder, istart, inroot-1, inmp);
        root->right=help(preorder, pstart+node_left+1, pend, inorder, inroot+1, iend, inmp);

        return root;
    } 
};