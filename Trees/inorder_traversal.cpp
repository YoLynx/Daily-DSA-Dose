// Inorder Traversal of a Binary Tree
// left, root, right


class Solution {
  public:
  
      void inorder(TreeNode *node, vector<int> &res) {
          if(node==nullptr) return;
  
          inorder(node->left, res);
          res.push_back(node->val);
          inorder(node->right, res);
      }
      
      vector<int> inorderTraversal(TreeNode* root) {
          vector<int> res;
          inorder(root, res);
          return res;
      }
  };