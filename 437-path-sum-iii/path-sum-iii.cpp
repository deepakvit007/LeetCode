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
    void solve(TreeNode* &root, int targetSum,long long sum,int &total,unordered_map<long long,int>&mp)
    {
        if(root == NULL)return;

        sum+=root->val;
        if(mp.find(sum - targetSum)!=mp.end())
        total+=mp[sum - targetSum];
        
        mp[sum]++;
        solve(root->left,targetSum,sum,total,mp);
        solve(root->right,targetSum,sum,total,mp);
        mp[sum]--;
        sum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>mp;

        long long sum = 0;
        int total = 0;
        
        mp[0] = 1;
        solve(root,targetSum,sum,total,mp);

        return total;

    }
};