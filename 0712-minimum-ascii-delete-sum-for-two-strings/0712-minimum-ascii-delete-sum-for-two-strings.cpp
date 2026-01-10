class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=s2[j]+dp[i+1][j+1];// adding ascii value sum
                }
                else {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

        int sum=0;
        for(char c:s1){
            sum+=(int)c;
        }
        for(char c:s2){
            sum+=(int)c;
        }
        return sum-2*dp[0][0];
    }
};