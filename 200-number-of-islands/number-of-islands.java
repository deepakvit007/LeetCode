class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {

    private void bfs(int i, int j, boolean visited[][], char[][] grid) {
        visited[i][j] = true;

        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(i, j));

        int delRow [] = {1,0,-1,0};
        int delCol [] = {0,-1,0,1};


        while (!q.isEmpty()) {
            int row = q.peek().first;
            int col = q.peek().second;
            q.remove();

            for (int k= 0; k <4; k++) {
                
                    int newRow = row + delRow[k];
                    int newCol = col + delCol[k];

                    // Check valid, unvisited land cell
                    if (newRow >= 0 && newRow < grid.length && newCol >= 0 && newCol < grid[0].length && grid[newRow][newCol] == '1' && !visited[newRow][newCol]) {
                        q.add(new Pair(newRow, newCol));
                        visited[newRow][newCol] = true;
                    }
                
            }
        }
    }

    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean visited[][] = new boolean[n][m];

        int count = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, visited, grid);
                }
            }
        }

        return count;
    }
}
