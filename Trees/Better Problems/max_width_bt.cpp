// Problem link : https://leetcode.com/problems/maximum-width-of-binary-tree/
// Brute force : We can use a level order traversal and keep track of the width at each level.
// We index the nodes as per our need that is 0(i)-based, left : 2i+1, right : 2i+2.... But what if uts a Skewed tree? It will give overflow.
// Therefore, at every level, we will try to make the nodes 0, 1, 2, 3... and so on.  For that we do, i=i-minimum index at that level. Then aplly 2i+1, 2i+2 to get left and right child respectively.

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        // int first, last;
        while(!q.empty()) {
            int size=q.size();
            int mmin=q.front().second;
            int first, last;

            for(int i=0;i<size;i++) {
                long long cid=q.front().second-mmin;
                TreeNode* node=q.front().first;
                q.pop();

                if(i==0) first=cid;
                if(i==size-1) last=cid;
                if(node->left) q.push({node->left, cid*2+1});
                if(node->right) q.push({node->right, cid*2+2});
            }
            ans=max(ans, last-first+1);
        }
        return ans;
        
    }
};