class Solution {
public:
    int n, m;
    const long long MOD = 1e9 + 7;

    pair<long long, long long> rec(int i, int j,
                                   vector<vector<int>>& grid,
                                   vector<vector<pair<long long,long long>>>& dp) {
        if (i == n-1 && j == m-1)
            return {grid[i][j], grid[i][j]};

        if (dp[i][j].first != LLONG_MIN) return dp[i][j];

        long long maxVal = LLONG_MIN, minVal = LLONG_MAX;

        if (i < n-1) {
            auto [dMax, dMin] = rec(i+1, j, grid, dp);
            long long a = grid[i][j] * dMax;
            long long b = grid[i][j] * dMin;
            maxVal = max(maxVal, max(a, b));
            minVal = min(minVal, min(a, b));
        }
        if (j < m-1) {
            auto [rMax, rMin] = rec(i, j+1, grid, dp);
            long long a = grid[i][j] * rMax;
            long long b = grid[i][j] * rMin;
            maxVal = max(maxVal, max(a, b));
            minVal = min(minVal, min(a, b));
        }

        return dp[i][j] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<pair<long long,long long>>> dp(
            n, vector<pair<long long,long long>>(m, {LLONG_MIN, LLONG_MIN})
        );

        auto [maxVal, minVal] = rec(0, 0, grid, dp);

        if (maxVal < 0) return -1;
        return (int)(maxVal % MOD);
    }
};