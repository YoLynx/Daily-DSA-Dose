// Problem link : https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/
// Easier version of vertical traversal, i meant the same idea but we must each node of same vertical only once.

class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> res;
        if(root==nullptr) return res;
        
        map<int, int> mp;
        queue<pair<Node* , int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it=q.front();
            q.pop();
            
            Node* node=it.first;
            int line=it.second;
            if(mp.find(line)==mp.end()) mp[line]=node->data;
            
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
        }
        
        for(auto p : mp) res.push_back(p.second);
        return res;
    }
};