1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        int n=nums.size();
5        deque<int>dq;
6        vector<int>ans;
7        for(int i=0;i<n;i++){
8            
9            while(!dq.empty()&&dq.front()<=i-k){
10                dq.pop_front();
11            }
12            while(!dq.empty()&&nums[dq.back()]<=nums[i]){
13                dq.pop_back();
14
15            }
16            dq.push_back(i);
17            if(i>=k-1)ans.push_back(nums[dq.front()]);
18        }
19        return ans;
20
21        
22    }
23};