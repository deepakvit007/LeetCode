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
    bool help(TreeNode* &root,int sum, int targetSum)
    {
        if(root == NULL)return false;
       
        sum += root->val;
        if(root->left ==NULL and root->right==NULL and sum == targetSum) return true;
        bool left  = help(root->left,sum,targetSum);
        bool right = help(root->right,sum,targetSum);
        
        sum -=root->val;
        
        return left || right;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return help(root,0,targetSum);

    }
};