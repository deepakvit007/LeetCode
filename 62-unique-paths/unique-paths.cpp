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
    int uniquePaths(int m, int n) {
       vector<vector<int>> dp(m, vector<int>(n, -1));
        return solveMemo(m-1,n-1,dp);
    }
};