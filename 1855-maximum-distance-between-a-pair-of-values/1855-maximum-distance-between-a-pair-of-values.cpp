class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int num=nums1[i];
            // now binary search of nums2
            int l=i,h=m-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(nums2[mid]>=num){
                    ans=max(ans,mid-i);
                    l=mid+1;
                }
                else{
                    // if bigger then we tend to find the smaller go in right space
                    h=mid-1;
                }
            }
        }
        return ans;
        
    }
};