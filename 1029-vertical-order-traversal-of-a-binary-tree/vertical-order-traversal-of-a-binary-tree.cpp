/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool compare(unordered_map<TreeNode*,pair<int,int>>A,unordered_map<TreeNode*,pair<int,int>>B)
    // {
    //     if()
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        if (!root) return ans;
        
        // Map to hold nodes according to their horizontal distance (HD) and level.
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue to perform BFS. Stores nodes along with their HD and level.
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int hd = p.second.first;   // Horizontal Distance
            int lvl = p.second.second; // Level
            
            nodes[hd][lvl].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {hd - 1, lvl + 1}});
            }
            if (node->right) {
                q.push({node->right, {hd + 1, lvl + 1}});
            }
        }
        
        // Extract the values from the nodes map to form the answer
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;

    }
};