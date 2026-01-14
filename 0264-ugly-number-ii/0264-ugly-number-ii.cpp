class Solution {
public:
    int nthUglyNumber(int n) {
    if(n==1) return 1;
    vector<int>dp(n);
    dp[0]=1;
    int i2=0,i3=0,i5=0;
    // pointers pointing multiples used we can only use ugly    numbers from dp so we point them to dp only 
    for(int i=1;i<n;i++){
        int next2=dp[i2]*2;
        int next3=dp[i3]*3;
        int next5=dp[i5]*5;
        dp[i]=min({next2,next3,next5});
        if(dp[i]==next2)i2++;
        if(dp[i]==next3)i3++;
        if(dp[i]==next5)i5++;

    }
    return dp[n-1];
        
    }
};