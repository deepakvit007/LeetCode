class Triple {

    int row;
    int col;
    int time;

    public Triple(int r, int c , int t)
    {
        this.row = r;
        this.col = c;
        this.time = t;

    }

}

class Solution {
    public int orangesRotting(int[][] grid) {

        int n = grid.length;
        int m = grid[0].length;

        int visited[][] = new int[n][m];
        //Arrays.fill(visited,0);
        Queue<Triple>q = new LinkedList<>();
        int cntFresh = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.add(new Triple(i,j,0));
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }

                if(grid[i][j] == 1)cntFresh++;
                
            }
        }

        int delRow[] = {1,0,-1,0};
        int delCol[] = {0,-1,0,1};
        int rotCnt = 0 ;

        int minTime = 0;
        while(!q.isEmpty())
        {
            int row = q.peek().row;
            int col = q.peek().col;
            int time = q.peek().time;
            q.remove();
            minTime = Math.max(minTime,time);

            for(int i = 0; i<4 ; i++)
            {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0)
                {
                    q.add(new Triple(nRow,nCol,time+1));
                    visited[nRow][nCol] = 2;
                    rotCnt++;

                }
            }
        }

        if(cntFresh!=rotCnt)return -1;


        return minTime;

        
    }
}