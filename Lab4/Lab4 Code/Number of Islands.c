#include <stdbool.h>

// Helper function for DFS
void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    // Bounds check and water check
    if (r < 0 || c < 0 || r >= gridSize || c >= gridColSize[r] || grid[r][c] == '0') {
        return;
    }

    grid[r][c] = '0';  // Mark as visited

    // Visit all 4 directions
    dfs(grid, gridSize, gridColSize, r + 1, c); // down
    dfs(grid, gridSize, gridColSize, r - 1, c); // up
    dfs(grid, gridSize, gridColSize, r, c + 1); // right
    dfs(grid, gridSize, gridColSize, r, c - 1); // left
}

// Main function
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridColSize[r]; c++) {
            if (grid[r][c] == '1') {
                count++;
                dfs(grid, gridSize, gridColSize, r, c);
            }
        }
    }
    return count;
}