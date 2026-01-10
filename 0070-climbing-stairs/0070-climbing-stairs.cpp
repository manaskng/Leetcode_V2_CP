class Solution {
public:
    int dp[46];

    // int rec(int n) {
    //     if (n == 0) return 1;
    //     if (n < 0) return 0;
    //     if (dp[n] != -1) return dp[n];
    //     return dp[n] = rec(n-1) + rec(n-2);
    // }

    int climbStairs(int n) {
        memset(dp, 0, sizeof(dp));
        //using tabulation
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};
