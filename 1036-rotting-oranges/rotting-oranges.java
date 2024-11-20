class Triple {
    int row;
    int col;
    int time;

    public Triple(int r, int c, int t) {
        this.row = r;
        this.col = c;
        this.time = t;
    }
}

class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length; // Number of rows
        int m = grid[0].length; // Number of columns

        // Create a visited array to track visited cells
        int visited[][] = new int[n][m];

        // Initialize the visited array to 0
        for (int i = 0; i < n; i++) {
            Arrays.fill(visited[i], 0); // Fill each row with 0
        }

        Queue<Triple> q = new LinkedList<>();
        int cntFresh = 0; // Count of fresh oranges

        // Traverse the grid to initialize the queue and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.add(new Triple(i, j, 0)); // Add rotten orange to the queue
                    visited[i][j] = 2; // Mark as visited
                } else {
                    visited[i][j] = 0; // Mark as unvisited
                }

                if (grid[i][j] == 1) cntFresh++; // Count fresh oranges
            }
        }

        int delRow[] = {1, 0, -1, 0}; // Row direction deltas
        int delCol[] = {0, -1, 0, 1}; // Column direction deltas
        int rotCnt = 0; // Count of oranges that become rotten
        int minTime = 0; // Minimum time to rot all oranges

        // Perform BFS to rot the oranges
        while (!q.isEmpty()) {
            int row = q.peek().row;
            int col = q.peek().col;
            int time = q.peek().time;
            q.remove();
            minTime = Math.max(minTime, time); // Track the maximum time

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // Check bounds, fresh orange condition, and if not visited
                if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && grid[nRow][nCol] == 1 && visited[nRow][nCol] == 0) {
                    q.add(new Triple(nRow, nCol, time + 1)); // Add to queue with incremented time
                    visited[nRow][nCol] = 2; // Mark as visited
                    rotCnt++; // Increment rotten count
                }
            }
        }

        // If the number of rotten oranges is less than the fresh count, return -1
        if (cntFresh != rotCnt) return -1;

        return minTime; // Return the minimum time required
    }
}
