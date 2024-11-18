class Pair {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {

    private void bfs(int i, int j, boolean visited[][], char[][] grid) {
        visited[i][j] = true;

        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(i, j));

        int delRow[] = { 1, 0, -1, 0 };
        int delCol[] = { 0, -1, 0, 1 };

        while (!q.isEmpty()) {
            int row = q.peek().first;
            int col = q.peek().second;
            q.remove();

            for (int k = 0; k < 4; k++) {
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

        AtomicInteger count = new AtomicInteger(0);

        IntStream
            .range(0, n)
            .forEach(
                i ->
                    IntStream
                        .range(0, m)
                        .forEach(
                            j -> {
                                if (!visited[i][j] && grid[i][j] == '1') {
                                    count.incrementAndGet();
                                    bfs(i, j, visited, grid);
                                }
                            }
                        )
            );
        return count.get();
    }
}
