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
    
    void bfs(TreeNode * root , vector<vector<int>>&ans,int count)
    {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        vector<int>an;
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            
            if(temp==NULL)
            {
              if(count%2==0)ans.push_back(an);
                else
                {
                    reverse(an.begin(),an.end());
                    ans.push_back(an);
                }
                
                an.clear();
                
                if(!q.empty())
                {
                    q.push(NULL);        
                }
                count++;
            }
            else
            {
                an.push_back(temp->val);
                
                if(temp->left)
                {
                    q.push(temp->left);
                    
                }
                 if(temp->right)
                {
                    q.push(temp->right);
                    
                

                }
            
            }
    }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL)return {};
        bfs(root,ans,0);
        
        return ans;
    }
};