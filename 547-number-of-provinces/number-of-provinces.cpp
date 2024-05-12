class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&visited)
    {
        visited[node] = 1;

        for(auto it : adj[node])
        {
            if(!visited[it])dfs(it,adj,visited);
        }
    }
    void adjMatrixToAdjList(vector<vector<int>>& isConnected,vector<int>adj[])
    {
           int n = isConnected.size();

           for(int i =0;i<n;i++)
           {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
           }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n+1];
        adjMatrixToAdjList(isConnected,adj);
        vector<int>visited(n+1,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
                ans++;

            }
        }

        return ans;
    }
};