class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;
        int cand=-1;
        while(i<n&&j<n2){
          if(nums1[i]==nums2[j]){
            cand=nums1[i];
            break;
          }
          else if(nums1[i]>nums2[j]){
            j++;
          }
          else if(nums1[i]<nums2[j]){
            i++;
          }
        }
        return cand;
        
    }
};