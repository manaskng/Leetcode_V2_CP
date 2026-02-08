class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        const long long NEG = LLONG_MIN / 4;

        // dp[i][j][t] = max score using nums1[i..], nums2[j..] with exactly t pairs
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(m + 1, vector<long long>(k + 1, NEG))
        );

        // Base case: t == 0 → score = 0
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j][0] = 0;
            }
        }

        // Fill DP bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int t = 1; t <= k; t++) {

                    // Skip nums1[i]
                    dp[i][j][t] = max(dp[i][j][t], dp[i + 1][j][t]);

                    // Skip nums2[j]
                    dp[i][j][t] = max(dp[i][j][t], dp[i][j + 1][t]);

                    // Take pair (i, j)
                    if (dp[i + 1][j + 1][t - 1] != NEG) {
                        dp[i][j][t] = max(
                            dp[i][j][t],
                            1LL * nums1[i] * nums2[j] + dp[i + 1][j + 1][t - 1]
                        );
                    }
                }
            }
        }

        return dp[0][0][k];
    }
};
