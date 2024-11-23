class Solution {

     // Depth-First Search (DFS) function to mark connected 'O' cells
    public void dfs(int row, int col, boolean visited[][], int [][] board, int n, int m) {
        // Mark the current cell as visited
        visited[row][col] = true;

        // Define possible directions to move: down, left, up, right
        int delRow[] = {1, 0, -1, 0};
        int delCol[] = {0, -1, 0, 1};

        // Traverse all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            // Check if the next cell is within bounds, not visited, and contains 'O'
            if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m &&
                !visited[nRow][nCol] && board[nRow][nCol] == 1) {
                // Recursively call DFS on the connected cell
                dfs(nRow, nCol, visited, board, n, m);
            }
        }
    }

    public int numEnclaves(int[][] board) {

        // Get dimensions of the board
        int n = board.length;        // Number of rows
        int m = board[0].length;     // Number of columns

        // Create a visited array to keep track of explored cells
        boolean visited[][] = new boolean[n][m];

        // Step 1: Perform DFS for all 'O' cells on the boundaries
        for (int i = 0; i < n; i++) {       // Traverse rows
            for (int j = 0; j < m; j++) {   // Traverse columns
                // If the cell is on the boundary and contains 'O', start DFS
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (!visited[i][j] && board[i][j] == 1 ) {
                        dfs(i, j, visited, board, n, m);
                    }
                }
            }
        }
        int ans = 0;

        // Step 2: Flip all unvisited 'O' cells to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is not visited and contains 'O', flip it to 'X'
                if (!visited[i][j] && board[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
}