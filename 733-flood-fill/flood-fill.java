class Solution {
    public void dfs(int[][] image, int[][] visited, int row, int col, int[] delRow, int[] delCol, int color, int initialColor) {
        int n = image.length;
        int m = image[0].length;
        
        // Mark the current cell as visited by coloring it
        visited[row][col] = color;

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            // Check if the new position is within bounds, not already visited with the new color,
            // and matches the initial color
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                && visited[newRow][newCol] != color && image[newRow][newCol] == initialColor) {
                dfs(image, visited, newRow, newCol, delRow, delCol, color, initialColor);
            }
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int[][] visited = new int[image.length][image[0].length];
        
        // Copy the original image into the visited array
        for (int i = 0; i < image.length; i++) {
            System.arraycopy(image[i], 0, visited[i], 0, image[0].length);
        }

        int[] delRow = {-1, 0, 0, 1};
        int[] delCol = {0, 1, -1, 0};
        int initialColor = image[sr][sc];
        
        // Perform the depth-first search
        dfs(image, visited, sr, sc, delRow, delCol, color, initialColor);
        return visited;
    }
}
