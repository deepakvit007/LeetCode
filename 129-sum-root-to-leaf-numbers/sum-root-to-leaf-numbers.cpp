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
    void solve(TreeNode* root,string temp,int &ans)
    {
        if(root== NULL)return;
       
        if(root->left == NULL and root->right == NULL)
        {
            temp +=to_string(root->val);
            ans +=stoi(temp);
            //temp = ""
            
           return;
        }

        temp +=to_string(root->val);
       
        solve(root->left,temp,ans);
        solve(root->right,temp,ans);
    }
    int sumNumbers(TreeNode* root) {
      int ans = 0;
      string temp="";
      solve(root,temp,ans);

      return ans;  
    }
};