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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == NULL)return root2;
        if(root2 == NULL)return root1;
        
        stack< pair<TreeNode*,TreeNode*> >st;
         
         st.push({root1,root2});

         while(!st.empty())
         {
            auto node = st.top();
            st.pop();

            TreeNode *bt1 = node.first;
            TreeNode *bt2 = node.second;
            
             bt1->val += bt2->val;

            if(bt1->left == NULL)
            {
                bt1->left = bt2->left;
            }
            else if(bt2->left)
            {
                st.push({bt1->left,bt2->left});
            }
            
            
            if(bt1->right == NULL)
            {
                bt1->right = bt2->right;
            }
            else if(bt2->right)
            {
                st.push({bt1->right,bt2->right});
            }
         }

        
        

        return root1;

    }
};