1class Solution {
2public:
3    vector<int> minBitwiseArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n);
6
7        for(int i = 0; i < n; i++){
8            int P = nums[i];
9
10            if((P & 1) == 0){
11                ans[i] = -1;
12                continue;
13            }
14
15            int t = 0;
16            int temp = P;
17            while(temp & 1){
18                t++;
19                temp >>= 1;
20            }
21
22            ans[i] = P - (1 << (t - 1));
23        }
24
25        return ans;
26    }
27};
28