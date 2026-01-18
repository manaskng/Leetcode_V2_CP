class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int max = std::min(rows, cols); // Maximum possible square size

        for (int size = max; size >= 2; size--) {
            for (int r = 0; r + size - 1 < rows; r++) {
                for (int c = 0; c + size - 1 < cols; c++) {
                    if (isMagic(grid, r, c, size)) {
                        return size;      // break immediately when found
                    }
                }
            }
        }

        return 1; // If no larger magic square found, smallest is 1
    }

    bool isMagic(vector<vector<int>>& grid, int r, int c, int size) {
        int targetSum = 0;

        // Sum of first row
        for (int j = 0; j < size; j++) {
            targetSum += grid[r][c + j];
        }

        // --- CHECK DIAGONALS FIRST ---
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < size; i++) {
            diag1 += grid[r + i][c + i];             // Main diagonal
            diag2 += grid[r + i][c + size - 1 - i];  // Anti-diagonal
        }
        if (diag1 != targetSum || diag2 != targetSum) return false;

        // --- THEN CHECK ROWS ---
        for (int i = 1; i < size; i++) { // Skip first row, already used for targetSum
            int sum = 0;
            for (int j = 0; j < size; j++) {
                sum += grid[r + i][c + j];
            }
            if (sum != targetSum) return false;
        }

        // --- THEN CHECK COLUMNS ---
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int i = 0; i < size; i++) {
                sum += grid[r + i][c + j];
            }
            if (sum != targetSum) return false;
        }

        return true;
    }
};