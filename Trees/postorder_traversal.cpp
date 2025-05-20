// Postorder Traversal of a Binary Tree
// left, right, root

class Solution {
  public:
  
      void postorder(TreeNode *node, vector<int> &res) {
          if(node==nullptr) return;
  
          postorder(node->left, res);
          postorder(node->right, res);
          res.push_back(node->val);
      }
  
      vector<int> postorderTraversal(TreeNode* root) {
          vector<int> res;
          postorder(root, res);
          return res;
      }
  };