// Given a binary tree, find its maximum depth.
// 1+max(depth of left subtree, depth of right subtree)


//Solution-1 : Recursive Approach
// Time Complexity: O(n) where n is the number of nodes in the tree
class Solution {
  public:
      int maxDepth(TreeNode* root) {
          if(root==nullptr) return 0;
  
          int lh=maxDepth(root->left);
          int rh=maxDepth(root->right);
          return 1+max(lh, rh);
      }
  };


//Solution-2 : Iterative Approach using stack
// Time Complexity: O(n) where n is the number of nodes in the tree

int maxDepth(TreeNode* root) {
  if(root==NULL) return 0;
  queue<TreeNode*> q;
  q.push(root);
  int depth=0;
  while(!q.empty()){
     int size=q.size();
   depth++;
     for(int i=0;i<size;i++){
         TreeNode* node=q.front();
         q.pop();
         if(node->left!=NULL) q.push(node->left);
         if(node->right!=NULL) q.push(node->right);
    }
  }   
  return depth;
 }