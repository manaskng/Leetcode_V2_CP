class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    
    vector<vector<int>> getFireTime(vector<vector<int>>& grid) {
        vector<vector<int>> fireTime(m, vector<int>(n, 1e9));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fireTime[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] == 2) continue;

                if (fireTime[nx][ny] > fireTime[x][y] + 1) {
                    fireTime[nx][ny] = fireTime[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return fireTime;
    }

    // Step 2: check if we can reach with given wait time
    bool canReach(vector<vector<int>>& grid,
                  vector<vector<int>>& fireTime,
                  int wait) {

        if (wait >= fireTime[0][0]) return false;

        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({0, 0, wait});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y, t] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) {
                return t <= fireTime[x][y];
            }

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                int nt = t + 1;

                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] == 2) continue;
                if (vis[nx][ny]) continue;

                // special handling for destination
                if (nx == m - 1 && ny == n - 1) {
                    if (nt <= fireTime[nx][ny]) {
                        return true;
                    }
                } else {
                    if (nt < fireTime[nx][ny]) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny, nt});
                    }
                }
            }
        }

        return false;
    }

    // Step 3: binary search answer
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> fireTime = getFireTime(grid);

        int lo = 0, hi = 1e9, ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReach(grid, fireTime, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (ans >= 1e9 / 2) return 1000000000;

        return ans;
    }
};