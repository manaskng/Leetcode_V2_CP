class Solution {
public:
    // int rec(int i, int n, vector<int>&nums,vector<int>&dp){
    //     if(i>=n)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     int skip=rec(i+1,n,nums,dp);
    //     int take=nums[i]+rec(i+2,n,nums,dp);
    //     return dp[i]=max(skip,take);
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
        
    }
};