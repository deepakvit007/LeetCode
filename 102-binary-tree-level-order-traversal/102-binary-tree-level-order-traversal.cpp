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
    void bfs(TreeNode* root,vector<vector<int>>&ans)
    {
        queue<TreeNode*>Q;
        Q.push(root);
        Q.push(NULL);
            vector<int>an;
        while(!Q.empty())
        {
           
            TreeNode* temp=Q.front();
            Q.pop();
            
            if(temp==NULL)
            {
                ans.push_back(an);
                an.clear();
                if(!Q.empty())
                {
                    Q.push(NULL);
                }
            }
             else
             {an.push_back(temp->val);
            //cout<<temp->val<<" ";
            if(temp->left)
                Q.push(temp->left);
            
            if(temp->right)
                Q.push(temp->right);}
        }

        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL)return {};
        bfs(root,ans);
        
        return ans;
    }
};