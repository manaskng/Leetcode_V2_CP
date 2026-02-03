class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if(n<=3) return false;
        // identify first peak then second belowest and then again peak of last
        int i=0; 
        if(nums[i]>=nums[i+1]) return false;
        else {
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        }
        if(i>n-3) return false;
        
        int j=i;
        if(j<n-1 && nums[j]<=nums[j+1]) return false;
        else {
            while(j<n-1 && nums[j]>nums[j+1]){
                j++;
            }
        }
        if(j>n-2) return false;
        int k=j;
        if( k<n-1 && nums[k]>=nums[k+1]) return false;
        else {
            while(k<n-1 && nums[k]<nums[k+1]){
                k++;
            }

        }
        // if checks only till n-2 
        return (k==n-1)? true:false;
    }
};