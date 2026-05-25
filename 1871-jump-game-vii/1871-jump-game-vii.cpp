class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // int n = s.size();
        // vector<bool> dp(n, false);
        // dp[0] = (s[0] == '0');

        // for (int i = 0; i < n; i++) {
        //     if (!dp[i]) continue;

        //     for (int j = minJump; j <= maxJump; j++) {
        //         int next = i + j;
        //         if (next < n && s[next] == '0') {
        //             dp[next] = true;
        //         }
        //     }
        // }

        // return dp[n - 1];
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int count = 0; 

        for (int i = 1; i < n; i++) {
            if (i >= minJump && dp[i - minJump]) count++;
            if (i > maxJump && dp[i - maxJump - 1]) count--;
            dp[i] = (s[i] == '0' && count > 0);
        }

        return dp[n - 1];
    }
};