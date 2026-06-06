class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftsum(n), rightsum(n);
        leftsum[0]=0;
        rightsum[n-1]=0;
        for(int i=1;i<n;i++){
            leftsum[i]=nums[i-1]+leftsum[i-1];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i]=nums[i+1]+rightsum[i+1];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]= abs(leftsum[i]-rightsum[i]);
        }
        return ans;
        
    }
};