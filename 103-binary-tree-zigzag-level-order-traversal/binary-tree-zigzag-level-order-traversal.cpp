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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> ans;
        int track=0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;

            while(size--)
            {
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left !=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }

            }
            if(track%2==1)
            {
                reverse(temp.begin(),temp.end());
            }

            ans.push_back(temp);
            track++;

        }

        return ans;
    }
};