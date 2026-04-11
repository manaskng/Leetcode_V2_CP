class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        mpp.reserve(n*2);
        for(int i=0;i<n;i++) {
            mpp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto &p:mpp){
            const vector<int>&v=p.second;
            if(v.size()<3) continue;
            for(int j=0;j+2<(int)v.size();j++){
                mini=min(mini,2*(v[j+2]-v[j]));
            }
        }
        return (mini==INT_MAX)? -1:mini;
        
        
    }
};