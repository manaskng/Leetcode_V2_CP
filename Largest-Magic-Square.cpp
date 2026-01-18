1class Solution {
2public:
3    int largestMagicSquare(vector<vector<int>>& grid) {
4        int rows = grid.size();
5        int cols = grid[0].size();
6
7        int max = std::min(rows, cols); // Maximum possible square size
8
9        for (int size = max; size >= 2; size--) {
10            for (int r = 0; r + size - 1 < rows; r++) {
11                for (int c = 0; c + size - 1 < cols; c++) {
12                    if (isMagic(grid, r, c, size)) {
13                        return size;      // break immediately when found
14                    }
15                }
16            }
17        }
18
19        return 1; // If no larger magic square found, smallest is 1
20    }
21
22    bool isMagic(vector<vector<int>>& grid, int r, int c, int size) {
23        int targetSum = 0;
24
25        // Sum of first row
26        for (int j = 0; j < size; j++) {
27            targetSum += grid[r][c + j];
28        }
29
30        // --- CHECK DIAGONALS FIRST ---
31        int diag1 = 0, diag2 = 0;
32        for (int i = 0; i < size; i++) {
33            diag1 += grid[r + i][c + i];             // Main diagonal
34            diag2 += grid[r + i][c + size - 1 - i];  // Anti-diagonal
35        }
36        if (diag1 != targetSum || diag2 != targetSum) return false;
37
38        // --- THEN CHECK ROWS ---
39        for (int i = 1; i < size; i++) { // Skip first row, already used for targetSum
40            int sum = 0;
41            for (int j = 0; j < size; j++) {
42                sum += grid[r + i][c + j];
43            }
44            if (sum != targetSum) return false;
45        }
46
47        // --- THEN CHECK COLUMNS ---
48        for (int j = 0; j < size; j++) {
49            int sum = 0;
50            for (int i = 0; i < size; i++) {
51                sum += grid[r + i][c + j];
52            }
53            if (sum != targetSum) return false;
54        }
55
56        return true;
57    }
58};