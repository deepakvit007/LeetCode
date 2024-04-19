class Solution {
public:
    int n,m;
    
    void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited)
    {
        visited[row][col] = 1;

        int delrow[] = {1,-1,0, 0};
        int delcol[] = {0 , 0 ,-1,1};

        for(int i = 0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 and nrow<n and ncol >=0 and
             ncol < m and grid[nrow][ncol] == '1' and !visited[nrow][ncol])
            {
               dfs(nrow,ncol,grid,visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        for(int i = 0;i<n;i++)
        {
          for(int j = 0;j<m;j++)
          {
            if(grid[i][j] == '1' and !visited[i][j])
            {
                dfs(i,j,grid,visited);
                count++;
            }
          }
        }

        return count;
    }
};