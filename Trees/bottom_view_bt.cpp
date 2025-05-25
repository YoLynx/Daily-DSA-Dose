// Problem link : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/
// The same approah as top view, but we must update the value of the node if it is already present in the map.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> res;
        if(root==nullptr) return res;
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it=q.front();
            q.pop();
            
            Node* node=it.first;
            int line=it.second;
            mp[line]=node->data;
            
            if(node->left) q.push({node->left, line-1});
            if(node->right) q.push({node->right, line+1});
            
        }
        for(auto p : mp) res.push_back(p.second);
        return res;
    }
};