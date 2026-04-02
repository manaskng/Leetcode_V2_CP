class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        const int NEG = -1e9;

        vector dp(m, vector(n, vector<int>(3, NEG)));

        // base
        if (coins[0][0] >= 0) {
            dp[0][0][0] = coins[0][0];
        } else {
            dp[0][0][0] = coins[0][0];
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k <= 2; k++) {
                    int best = NEG;

                    // from top
                    if (i > 0) best = max(best, dp[i-1][j][k]);
                    // from left
                    if (j > 0) best = max(best, dp[i][j-1][k]);

                    if (coins[i][j] >= 0) {
                        if (best != NEG)
                            dp[i][j][k] = coins[i][j] + best;
                    } else {
                        // take hit
                        if (best != NEG)
                            dp[i][j][k] = coins[i][j] + best;

                        // neutralize
                        if (k > 0) {
                            int best2 = NEG;
                            if (i > 0) best2 = max(best2, dp[i-1][j][k-1]);
                            if (j > 0) best2 = max(best2, dp[i][j-1][k-1]);

                            if (best2 != NEG)
                                dp[i][j][k] = max(dp[i][j][k], best2);
                        }
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};