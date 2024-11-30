class Solution {
    public boolean canFinish(int V, int[][] prerequisites) {
        // Create adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] prereq : prerequisites) {
            adj.get(prereq[1]).add(prereq[0]);
        }

        // Calculate indegree for each node
        int[] indegree = new int[V];
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj.get(i)) {
                indegree[neighbor]++;
            }
        }

        // Initialize queue and add nodes with 0 indegree
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }

        // Perform topological sort
        int count = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            count++;
            for (int neighbor : adj.get(node)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.add(neighbor);
                }
            }
        }

        // If the count matches the number of nodes, return true
        return count == V;
    }
}