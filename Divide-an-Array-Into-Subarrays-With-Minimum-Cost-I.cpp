1class Solution {
2public:
3    int minimumCost(vector<int>& nums) {
4        int n=nums.size();
5        int sum=nums[0];
6        vector<int>nu;
7        for(int i=1;i<n;i++){
8            nu.push_back(nums[i]);
9        }
10        sort(nu.begin(),nu.end());
11        return sum+nu[0]+nu[1];
12        
13    }
14};