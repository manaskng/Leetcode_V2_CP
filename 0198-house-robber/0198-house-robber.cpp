class Solution {
public:
    int rec(int i, int n, vector<int>&nums,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int skip=rec(i+1,n,nums,dp);
        int take=nums[i]+rec(i+2,n,nums,dp);
        return dp[i]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return rec(0,n,nums,dp);
        
    }
};