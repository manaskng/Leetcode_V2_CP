class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int x, int y, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int r, int c) {

        if (x == r - 1) return true;

        vis[x][y] = 1;

        for (auto d : dirs) {
            int nx = x + d.first;
            int ny = y + d.second;

            if (nx >= 0 && nx < r && ny >= 0 && ny < c &&
                !vis[nx][ny] && grid[nx][ny] == 0) {

                if (dfs(nx, ny, grid, vis, r, c))
                    return true;
            }
        }
        return false;
    }

    bool canCross(int day, int r, int c, vector<vector<int>>& cells) {
        vector<vector<int>> grid(r, vector<int>(c, 0));

        // flood till day
        for (int i = 0; i <= day; i++) {
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        vector<vector<int>> vis(r, vector<int>(c, 0));

        for (int j = 0; j < c; j++) {
            if (grid[0][j] == 0 && !vis[0][j]) {
                if (dfs(0, j, grid, vis, r, c))
                    return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = cells.size() - 1;
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canCross(mid, row, col, cells)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans + 1;
    }
};
