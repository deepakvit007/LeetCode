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
    void preorder(TreeNode* &root, vector<int>&an)
{
    
    if(root==NULL)
    {
        return;
    }
    an.push_back(root->val);
    preorder(root->left, an);

    preorder(root->right,an);
    
    
}
    vector<int> preorderTraversal(TreeNode* root) {
        
 
        if(root == NULL)return {};
        stack<TreeNode*>st;
        vector<int>ans;
        st.push(root);
        while(!st.empty())
        {
            auto node = st.top();
             st.pop();
             ans.push_back(node->val);
            if(node->right !=NULL)
            {
                st.push(node->right);
            }
            if(node->left !=NULL)
            {
                st.push(node->left);
            }
        }
        return ans;
     
    }
};