class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        bool first=true;
        bool second=false;
        int firstscore=0;
        int secondscore=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                first=!first;
                second=!second;
                
                
            }
            if((i-5)%6==0){
                first=!first;
                second=!second;
            }
             if(first){
                firstscore+=nums[i];
            }
             if(second){
                secondscore+=nums[i];
            }
        }
        return firstscore-secondscore;
        
    }
};