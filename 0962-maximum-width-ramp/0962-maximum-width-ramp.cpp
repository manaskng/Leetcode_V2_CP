class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        // we make a decreasing stack from L to R so that we store the lowest elements from left to right in order so that we can traverse from right and start checking with smallest elements and move to maximise the distance btw right and left elements
        for(int i=0;i<n;i++){
            while(st.empty()||nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
         int maxi=INT_MIN;

        for(int j=n-1;j>=0;j--){
            while(!st.empty()&&nums[st.top()]<=nums[j]){
                maxi=max(maxi,j-st.top());
                st.pop();
            }
        }
        return maxi;
    }
};