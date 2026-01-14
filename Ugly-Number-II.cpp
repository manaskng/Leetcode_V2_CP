1class Solution {
2public:
3    int nthUglyNumber(int n) {
4    if(n==1) return 1;
5    vector<int>dp(n);
6    dp[0]=1;
7    int i2=0,i3=0,i5=0;
8    // pointers pointing multiples used we can only use ugly    numbers from dp so we point them to dp only 
9    for(int i=1;i<n;i++){
10        int next2=dp[i2]*2;
11        int next3=dp[i3]*3;
12        int next5=dp[i5]*5;
13        dp[i]=min({next2,next3,next5});
14        if(dp[i]==next2)i2++;
15        if(dp[i]==next3)i3++;
16        if(dp[i]==next5)i5++;
17
18    }
19    return dp[n-1];
20        
21    }
22};