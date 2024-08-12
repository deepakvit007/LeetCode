/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> inorderTraversal(TreeNode *root)
        {
            if (root == NULL) return {};
            vector<int> ans;
            stack<TreeNode*> s;

            auto temp = root;
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }

            while (!s.empty())
            {
                auto curr = s.top();
                s.pop();

                ans.push_back(curr->val);

                auto temp = curr->right;
                while (temp)
                {
                    s.push(temp);
                    temp = temp->left;
                }
            }

            return ans;
        }
};