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
    int solve(TreeNode* root, int &ans)
    {
        if(root == NULL)return 0;

        int left = solve(root->left,ans);
        int right = solve(root->right,ans);

        int khud_ko_ans = left + right + 1;

        ans = max(khud_ko_ans,ans);

        int dusre_ke_liye = max(left,right) + 1;
        return dusre_ke_liye;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        
        solve(root,ans);
        return ans-1;
    }
};