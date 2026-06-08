class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>lesser, greater;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                lesser.push_back(nums[i]);
            }
            else  if(nums[i] >pivot){
                greater.push_back(nums[i]);
                
            }
            else {
                cnt++;
            }
        }
        vector<int>ans;
        for(int i=0;i<lesser.size();i++){
            ans.push_back(lesser[i]);
        }
        for(int i=0;i<cnt;i++){
            ans.push_back(pivot);
        }
        for(int i=0;i<greater.size();i++){
            ans.push_back(greater[i]);
        }
        return ans;
        
    }
};