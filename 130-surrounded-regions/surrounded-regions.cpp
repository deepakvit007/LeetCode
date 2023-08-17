class Solution
{
    public:
        void dfs(int i, int j, vector<vector < char>> &board, vector< vector< int>> &vis)
        {
            if (i < 0 or j < 0 or i >= board.size() or
             j >= board[0].size() or board[i][j] == 'X' or vis[i][j]==1)
                return;

            vis[i][j] = 1;

            dfs(i + 1, j, board, vis);
            dfs(i - 1, j, board, vis);
            dfs(i, j - 1, board, vis);
            dfs(i, j + 1, board, vis);
        }
    void solve(vector<vector < char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector < int>> vis(m, vector<int> (n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 or i == m - 1 or j == 0 or j == n - 1) and vis[i][j] == 0 and board[i][j] == 'O')
                {
                    dfs(i, j, board, vis);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] == 0 and board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};