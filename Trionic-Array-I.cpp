1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int n=nums.size();
5        if(n<=3) return false;
6        // identify first peak then second belowest and then again peak of last
7        int i=0; 
8        if(nums[i]>=nums[i+1]) return false;
9        else {
10        while(i<n-1 && nums[i]<nums[i+1]){
11            i++;
12        }
13        }
14        if(i>n-3) return false;
15        
16        int j=i;
17        if(j<n-1 && nums[j]<=nums[j+1]) return false;
18        else {
19            while(j<n-1 && nums[j]>nums[j+1]){
20                j++;
21            }
22        }
23        if(j>n-2) return false;
24        int k=j;
25        if( k<n-1 && nums[k]>=nums[k+1]) return false;
26        else {
27            while(k<n-1 && nums[k]<nums[k+1]){
28                k++;
29            }
30
31        }
32        // if checks only till n-2 
33        return (k==n-1)? true:false;
34    }
35};