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
    void solve(TreeNode*root,vector<string>temp,int &result)
    {
        if(root == NULL)return;
         temp.push_back(to_string(root->val));
        if(!root->left and !root->right)
        {
            string curr ="";
            for(auto x : temp)
            {
           
                curr += x;

            }
            result+=stoi(curr);
        } 

       
        solve(root->left,temp,result);
        solve(root->right,temp,result);
        temp.pop_back();

    }
    int sumNumbers(TreeNode* root) {
        int result = 0;
        vector<string>temp;
        solve(root,temp,result);
        return result;
    }
};