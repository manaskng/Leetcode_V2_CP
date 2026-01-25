class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int mindiff=INT_MAX;
        sort(begin(nums),end(nums));
        for(int i=k-1;i<n;i++){
            mindiff=min(mindiff,nums[i]-nums[i-k+1]);
        }
        return mindiff;
        
    }
};