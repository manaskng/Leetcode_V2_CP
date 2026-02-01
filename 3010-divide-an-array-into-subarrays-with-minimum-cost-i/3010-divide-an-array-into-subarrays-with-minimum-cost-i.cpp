class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        vector<int>nu;
        for(int i=1;i<n;i++){
            nu.push_back(nums[i]);
        }
        sort(nu.begin(),nu.end());
        return sum+nu[0]+nu[1];
        
    }
};