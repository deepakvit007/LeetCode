class Solution {
public:
    int solve(int row,int col)
    {
        //base condition
        if(row == 0 and col == 0)return 1;

        if(row<0 || col<0)return 0;

        int left = solve(row-1,col);
        int up = solve(row,col-1);

        return left + up;
    }
    int solveMemo(int row,int col, vector<vector<int>> &dp)
    {
        //base condition
        if(row == 0 and col == 0)return 1;

        if(row<0 || col<0)return 0;

        if(dp[row][col]!=-1)return dp[row][col];

        int left = solveMemo(row-1,col,dp);
        int up = solveMemo(row,col-1,dp);

        return dp[row][col] = left + up;
    }
    int solveTab(int row,int col)
    {
        vector<vector<int>> dp(row, vector<int>(col, -1));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i == 0 and j == 0)dp[i][j] = 1;

                else
                {
                    int left = 0;
                    int up = 0;

                    if(i>0)left = dp[i-1][j];
                    if(j>0)up = dp[i][j-1];

                    dp[i][j] = up + left;
                }


            }
        }

        return dp[row-1][col-1];

    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solveMemo(m-1,n-1,dp);
        return solveTab(m,n);
    }
};