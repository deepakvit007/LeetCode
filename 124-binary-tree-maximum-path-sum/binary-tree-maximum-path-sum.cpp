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
    int solve(TreeNode* &root,int &res)
    {
         if(root == NULL)return 0;

         int left = solve(root->left,res);
         int right = solve(root->right,res);
         
         //edge case when both left and right subtree return negative value
         // so here we not include them in our answer 
         if(left < 0 and right < 0) {left = 0;right=0;}
          
         //we send maxAns possible to next node 
         int dusre_ke_liye_ans = root->val + max(left , right);
         
         //we assume that node will be the ans
         int me_khud_ko_ans_manogaa = max(dusre_ke_liye_ans , root->val + left + right);
         
         //store the ans;
         res = max(res , me_khud_ko_ans_manogaa);
        
         return  dusre_ke_liye_ans ;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};