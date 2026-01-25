1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        int n=nums.size();
5        int mindiff=INT_MAX;
6        sort(begin(nums),end(nums));
7        for(int i=k-1;i<n;i++){
8            mindiff=min(mindiff,nums[i]-nums[i-k+1]);
9        }
10        return mindiff;
11        
12    }
13};