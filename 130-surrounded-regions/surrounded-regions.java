class Solution {
    public void dfs(int row , int col ,  boolean visited[][] ,char[][] board, int n, int m )
    {
        visited[row][col] = true;
        int delRow[] = {1,0,-1,0};
        int delCol[] = {0,-1,0,1};

        for(int i=0;i<4;i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && visited[nRow][nCol] == false && board[nRow][nCol]=='O')
            {
                dfs(nRow,nCol,visited,board,n,m);
            }
        }
    }
    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;
        boolean visited[][] = new boolean[n][m];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j == m-1 )
                {
                    if(!visited[i][j] && board[i][j] == 'O')
                    dfs(i,j,visited,board,n,m);
                }
            }
        }
        
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }



    }
}