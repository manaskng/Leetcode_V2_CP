class Solution {
public:
    int dp[32][2][2];

    int solve(string &s, int idx, int prevOne, int tight) {
        if (idx == s.size()) return 1;

        if (dp[idx][prevOne][tight] != -1) return dp[idx][prevOne][tight];

        int limit = tight ? s[idx] - '0' : 1;
        int ans = 0;

        for (int i = 0; i <= limit; i++) {
            if (prevOne == 1 && i == 1) continue; // consecutive ones not allowed
            int newTight = tight & (i == (s[idx] - '0'));
            ans += solve(s, idx + 1, i, newTight);
        }

        return dp[idx][prevOne][tight] = ans;
    }

    int findIntegers(int n) {
        string s = "";
        while (n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }
        reverse(s.begin(), s.end());

        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0, 1);
    }
};
