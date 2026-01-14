/*
Problem: Island Perimeter

Approach:
- Traverse every cell in the grid
- For each land cell, check its four sides
- Add 1 to the perimeter for every side that touches water or the grid boundary

Time Complexity: O(m × n)
Space Complexity: O(1)
*/

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) {
                // check top
                if (i == 0 || grid[i - 1][j] == 0)
                    perimeter++;
                // check bottom
                if (i == gridSize - 1 || grid[i + 1][j] == 0)
                    perimeter++;
                // check left
                if (j == 0 || grid[i][j - 1] == 0)
                    perimeter++;
                // check right
                if (j == gridColSize[i] - 1 || grid[i][j + 1] == 0)
                    perimeter++;
            }
        }
    }
    return perimeter;
}
