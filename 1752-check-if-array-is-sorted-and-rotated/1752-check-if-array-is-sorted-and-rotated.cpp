class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int peak=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                peak=i;
                break;// should be maximum
            }
        }
        if(peak==-1) return true;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+n-peak-1);
        reverse(nums.begin()+n-peak-1,nums.end());

        bool sorted=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                sorted =false;
                
            }
        }
       return sorted;
        
    }
};