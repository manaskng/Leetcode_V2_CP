class Solution {
public:
    vector<pair<int,int>> dirs = {{0,-1}, {-1,0}, {1,0}, {0,1}};

    int dfs(int i, int j, vector<vector<int>>& grid, int id) {
        int n = grid.size();
        grid[i][j] = id;
        int area = 1;

        for (auto &dir : dirs) {
            int ni = i + dir.first;
            int nj = j + dir.second;

            if (ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj] == 1) {
                area += dfs(ni, nj, grid, id);
            }
        }
        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int> area;
        int id = 2;

        // 🔥 Step 1: label islands
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 1) {
                    area[id] = dfs(i, j, grid, id);
                    id++;
                }
            }
        }

        int ans = 0;

        // 🚀 Step 2: try flipping 0
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int curr = 1;

                    for (auto &dir : dirs) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;

                        if (ni>=0 && nj>=0 && ni<n && nj<n) {
                            int nid = grid[ni][nj];
                            if (nid > 1 && !seen.count(nid)) {
                                curr += area[nid];
                                seen.insert(nid);
                            }
                        }
                    }

                    ans = max(ans, curr);
                }
            }
        }

        // edge case: all 1s
        if (ans == 0) return n*n;

        return ans;
    }
};