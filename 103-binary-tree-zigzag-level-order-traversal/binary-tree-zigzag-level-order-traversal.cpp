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
    vector<vector<int>>ans;
    if(root == NULL)return ans;

       queue<TreeNode *>q;
       q.push(root);
       int track = 0;
       while(!q.empty())
       {
           int size = q.size();
           vector<int>level;
           
           for(int i=0;i<size;i++)
           {
               auto node = q.front();
               q.pop();

               level.push_back(node->val);

               if(node->left!=NULL)
               {
                   q.push(node->left);
               }

               if(node->right!=NULL)
               {
                   q.push(node->right);
               }
           }
           if(track%2!=0)
           {
                reverse(level.begin(),level.end());
                ans.push_back(level);
           }
           else
           {
                ans.push_back(level);
           }
         track++;

       }

       return ans;

    }
};