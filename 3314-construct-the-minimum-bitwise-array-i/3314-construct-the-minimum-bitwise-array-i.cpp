class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans[i]=-1;
            }
            else {
                for(int j=1;j<nums[i];j++){
                    if((j|(j+1))==nums[i]){
                       ans[i]=j;
                       break;
                    }
                }
            }

        }
        return ans;
        
    }
};