class Solution {
public:
int dp[501][501];

    int rec(int i, int j, int n,int m, vector<int>&nums1,vector<int>&nums2){
         if(i==n||j==m){
            return INT_MIN;// exhauseted path
         }
         if(dp[i][j]!=INT_MIN){
            return dp[i][j];
         }

         int take=nums1[i]*nums2[j] +max(0,rec(i+1,j+1,n,m,nums1,nums2));
         int skipa=rec(i+1,j,n,m,nums1,nums2);
         int skipb=rec(i,j+1,n,m,nums1,nums2);
         return dp[i][j]=max({take,skipa,skipb});

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=INT_MIN;
            }
        }
        return rec(0,0,n,m,nums1,nums2);
        
    }
};