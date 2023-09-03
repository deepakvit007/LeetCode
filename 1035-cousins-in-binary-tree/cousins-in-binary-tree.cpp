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
    TreeNode* findNode(TreeNode*root,int x)
    {
        if(root == NULL)return root;

        if(root->val == x)return root;

        TreeNode * ans = findNode(root->left,x);
        if(ans!= NULL)return ans;
        return findNode(root->right,x);

    }
    int level(TreeNode * root, TreeNode* x , int lvl )
    {
        if(root == NULL)return 0;

        if(root == x)return lvl;
           
        int plvl = level(root->left,x,lvl+1);
        if(plvl != 0)return plvl;
        return level(root->right,x,lvl+1);


    }

    bool sibling(TreeNode * root, TreeNode* xx,TreeNode* yy)
    {
        if(root == NULL)return false;

        return ((root->left == xx and root->right == yy) || 
        (root->left == yy and root->right == xx )|| sibling(root->left,xx,yy)
         || sibling(root->right,xx,yy) );

    }
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xx = findNode(root,x);
        TreeNode* yy = findNode(root,y);

        return ( (level(root,xx,0) == level(root,yy,0)) and !sibling(root,xx,yy));
      

    }
};