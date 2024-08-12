/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> levelOrder(TreeNode *root)
        {
            if (root == NULL) return {};

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    vector<vector<int>> ans;

    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();

        // Ensure ans has enough space for the current level
        if (ans.size() <= level) {
            ans.push_back({});
        }

        // Add the current node's value to the corresponding level
        ans[level].push_back(node->val);

        // Enqueue children with the level incremented by 1
        if (node->left != NULL) {
            q.push({node->left, level + 1});
        }
        if (node->right != NULL) {
            q.push({node->right, level + 1});
        }
    }

    return ans;
        }
};