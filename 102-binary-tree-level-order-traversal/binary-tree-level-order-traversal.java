/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Pair {
    TreeNode node;
    int level;

    public Pair(TreeNode node, int level) {
        this.node = node;
        this.level = level;
    }
}
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;

        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair currentPair = queue.poll();
            TreeNode node = currentPair.node;
            int level = currentPair.level;

            // Ensure ans has enough space for the current level
            if (ans.size() <= level) {
                ans.add(new ArrayList<>());
            }

            // Add the current node's value to the corresponding level
            ans.get(level).add(node.val);

            // Enqueue children with the level incremented by 1
            if (node.left != null) {
                queue.add(new Pair(node.left, level + 1));
            }
            if (node.right != null) {
                queue.add(new Pair(node.right, level + 1));
            }
        }

        return ans; 
    }
}