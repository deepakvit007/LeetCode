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
    
    void lob(TreeNode* root, vector<vector<int>>&ans)
    {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
     vector<int>an;
        while(!q.empty())
        {
           
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL)
            {
                ans.push_back(an);
                an.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                an.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return {};
        
        lob(root,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};