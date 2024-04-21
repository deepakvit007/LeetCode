class Solution {
public:
    bool dfs(int src, int dest,vector<int>adj[], vector<int>&visited)
    {
        visited[src]=1;

        if(src == dest)return true;

        for(auto it : adj[src])
        {
            if(!visited[it])
            {
                if(dfs(it,dest,adj,visited))
                return true;
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int>adj[n+1];
         
         for(auto edge : edges)
         {
             int u = edge[0];
             int v = edge[1];

             adj[u].push_back(v);
             adj[v].push_back(u);
         }

         vector<int>visited(n,0);

         return dfs(src,dest,adj,visited);
    }
};