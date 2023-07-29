class Solution
{
    public:
        bool isSafe(int row,int col,char val,vector<vector < char>> &board)
        {
            for(int i=0;i<board.size();i++)
            {
               if(board[row][i] == val || board[i][col] == val)
               {
                   return false;
               }

                int smallMatrixRow = (3*(row/3) + i/3);
                int smallMatrixCol = (3*(col/3) + i%3);

               if(board[smallMatrixRow][smallMatrixCol] == val)
               {
                   return false;
               }
            }

            return true;
        }
        bool solve(vector<vector < char>> &board)
        {
            int n = board.size();

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == '.')
                    {
                        for (char k = '1'; k <= '9'; k++)
                        {
                            if (isSafe(i,j, k, board))
                            {
                                board[i][j] = k;

                                bool solPossible = solve(board);

                                if (solPossible == true)
                                {
                                    return true;
                                }
                                else
                                {
                                    board[i][j] = '.';
                                }
                            }
                        }
                       return false;
                    }
                   
                }
               
            }
        return true;
        }
    void solveSudoku(vector<vector < char>> &board) {
        solve(board);
    }
};