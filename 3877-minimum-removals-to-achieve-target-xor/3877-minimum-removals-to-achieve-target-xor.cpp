class Solution {
public:
    int n, maxXor;
    vector<vector<int>> memo;
    
    int rec(int i, int xori, vector<int>& nums, int target) {
        if(i >= n) {
            return (xori == target) ? 0 : INT_MIN/2;
        }
        
        if(memo[i][xori] != -1) return memo[i][xori];
        
        int take = 1 + rec(i+1, xori ^ nums[i], nums, target);
        int skip = rec(i+1, xori, nums, target);
        
        return memo[i][xori] = max(take, skip);
    }

    int minRemovals(vector<int>& nums, int target) {
        n = nums.size();
        
        // Find XOR range
        maxXor = 1;
        int maxVal = *max_element(nums.begin(), nums.end());
        maxVal = max(maxVal, target);  
        while(maxXor <= maxVal) maxXor <<= 1;
        
       
        memo.assign(n, vector<int>(maxXor, -1));
        
        int totalXor = 0;
        for(int x : nums) totalXor ^= x;
        if(totalXor == target) return 0;
        
        int maxLen = rec(0, 0, nums, target);
        if(maxLen < 0) return -1;
        return n - maxLen;
    }
};