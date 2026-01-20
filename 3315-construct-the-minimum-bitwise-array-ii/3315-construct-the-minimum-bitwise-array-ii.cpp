class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            int P = nums[i];

            if((P & 1) == 0){
                ans[i] = -1;
                continue;
            }

            int t = 0;
            int temp = P;
            while(temp & 1){
                t++;
                temp >>= 1;
            }

            ans[i] = P - (1 << (t - 1));
        }

        return ans;
    }
};
