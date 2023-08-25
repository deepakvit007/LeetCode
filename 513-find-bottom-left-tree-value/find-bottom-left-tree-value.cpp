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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans = root->val;
            vector<int>arr;

        while(!q.empty())
        {
            arr.clear();
            int n = q.size();
            while(n--)
            {
                auto node = q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left!=NULL)
                {
                    q.push(node->left);
                    //ans = node->left->val;
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                   
                }
            }

        }
        return arr[0];
    }
};