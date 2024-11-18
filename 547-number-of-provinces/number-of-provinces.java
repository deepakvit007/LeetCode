class Solution {
    void dfs(int node,boolean visited[],ArrayList<ArrayList<Integer>> adj)
    {
        visited[node] = true;

        for(int neighbour : adj.get(node))
        {
            if(!visited[neighbour])
            dfs(neighbour,visited,adj);
        }
    }
    public int findCircleNum(int[][] isConnected) {

        int V = isConnected.length;

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
         // Initialize adjacency list
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }


        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    adj.get(i).add(j);
                    adj.get(j).add(i);

                }
            }
        }

        boolean visited[] = new boolean[V];
        int count = 0;

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,adj);
                count++;
            }
        }
        
        return count;

    }
}
