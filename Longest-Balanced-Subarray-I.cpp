1class Solution {
2public:
3    int longestBalanced(vector<int>& nums) {
4        int n=nums.size();
5        int longest=0;
6        //atleast len will be 2 
7        for(int i=0;i<n;i++){
8            unordered_set<int>odd,even;
9            for(int j=i;j<n;j++){
10                if(nums[j]%2){
11                    odd.insert(nums[j]);
12                }
13                else {
14                    even.insert(nums[j]);
15                }
16                if(odd.size()==even.size()){
17                    longest=max(longest,j-i+1);
18
19                }
20
21            }
22            odd.clear();
23            even.clear();
24        }
25        return longest;
26        
27    }
28};