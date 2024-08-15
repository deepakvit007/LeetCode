/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
       	// Comparator function to sort nodes by HD, Level, and Value
    bool static customComparator(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
    {
        if (get<0> (a) != get<0> (b))	// Compare by HD
            return get<0> (a)<get<0> (b);
        if (get<1> (a) != get<1> (b))	// Compare by Level
            return get<1> (a)<get<1> (b);
        return get<2> (a)<get<2> (b);	// Compare by Value
    }
    void preorderTraversal(TreeNode *node, int hd, int level, vector<tuple<int, int, int>> &nodes)
    {
        if (!node) return;

       	// Capture the node's HD, level, and value
        nodes.push_back({ hd,
            level,
            node->val });

       	// Traverse left with updated HD and level
        preorderTraversal(node->left, hd - 1, level + 1, nodes);

       	// Traverse right with updated HD and level
        preorderTraversal(node->right, hd + 1, level + 1, nodes);
    }

    vector<vector < int>> verticalTraversal(TreeNode *root)
    {
        vector<tuple<int, int, int>> nodes;	// Stores tuples of (HD, Level, Value)
        vector<vector < int>> ans;

       	// Helper function to perform preorder traversal
        preorderTraversal(root, 0, 0, nodes);

       	// Sort the nodes using the custom comparator function
        sort(nodes.begin(), nodes.end(), customComparator);

       	// Group nodes by HD
        map<int, vector < int>> groupedNodes;
        for (auto &node: nodes)
        {
            int hd = get<0> (node);
            int val = get<2> (node);
            groupedNodes[hd].push_back(val);
        }

       	// Collect the grouped nodes into the answer
        for (auto &p: groupedNodes)
        {
            ans.push_back(p.second);
        }

        return ans;
    }
};