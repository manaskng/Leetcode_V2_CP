class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int mindiff=INT_MAX;
        for(int i=0;i<n-1;i++){
            mindiff=min(mindiff,nums[i+1]-nums[i]);
        }
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]==mindiff){
                vector<int>ans1;
                ans1.push_back(nums[i]);
                ans1.push_back(nums[i+1]);
                ans.push_back(ans1);

            }
        }
        
        return ans;
    }
};