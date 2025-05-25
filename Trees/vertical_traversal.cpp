// Hardest tree problem tbh 
// Problem Link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Approach : We use a map to store the nodes at each horizontal distance from the root. We also maintain a queue to perform a level order traversal of the tree. For each node, we calculate its horizontal distance from the root and insert it into the map. After processing all nodes, we sort the keys of the map and construct the result vector by traversing the map in sorted order.


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int ,map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto p=q.front();
            q.pop();

            TreeNode* node=p.first;
            int x=p.second.first, y=p.second.second;
            mp[x][y].insert(node->val);

            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1, y+1}});
        }
        vector<vector<int>> res;
        for(auto p : mp) {
            vector<int> v;
            for(auto t : p.second) {
                v.insert(v.end(), t.second.begin(), t.second.end());
            }
            res.push_back(v);
        }
        return res;
    }
};