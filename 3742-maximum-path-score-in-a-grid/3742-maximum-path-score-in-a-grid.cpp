class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(k + 1, -1));
        vector<vector<int>> ndp(m, vector<int>(k + 1, -1));

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {

            for (int col = 0; col < m; col++)
                fill(ndp[col].begin(), ndp[col].end(), -1);

            for (int j = 0; j < m; j++) {

                int addScore = grid[i][j];
                int addCost  = (grid[i][j] == 0 ? 0 : 1);

                for (int cost = 0; cost <= k; cost++) {

                    if (dp[j][cost] != -1 && cost + addCost <= k)
                        ndp[j][cost + addCost] =
                            max(ndp[j][cost + addCost], dp[j][cost] + addScore);

                    if (j > 0 && ndp[j - 1][cost] != -1 && cost + addCost <= k)
                        ndp[j][cost + addCost] =
                            max(ndp[j][cost + addCost], ndp[j - 1][cost] + addScore);
                }
            }

            dp = ndp;
        }

        int maxi = -1;
        for (int cost = 0; cost <= k; cost++)
            maxi = max(maxi, dp[m - 1][cost]);

        return maxi;
    }
};