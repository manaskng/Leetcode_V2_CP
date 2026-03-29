class Solution {
public:
    bool check(vector<int>&nums,int k){
        int n=nums.size();
        int prevmax=0;
        for(int i=0;i<n;i+=k){
            if(prevmax>nums[i]) return false;
            bool peak=false;
            int curmax=nums[i];
            for(int j=i+1;j<i+k;j++){
                if(nums[j]<prevmax) return false;
                if(nums[j-1]>nums[j]){
                    if(peak) return false;// no two peaks possible
                    peak=true;
                }
                curmax=max(curmax,nums[j]);
                

            }
            if(peak){
                    if(nums[i]<nums[i+k-1]) return false;
            }
            prevmax=curmax;

        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int k=1;k<=n;k++){
            if(n%k!=0) continue;
            else {
              if(check(nums,k)){
                sum+=k;
              }
            }
        }
        return sum;
        
    }
};