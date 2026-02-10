class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int longest=0;
        //atleast len will be 2 
        for(int i=0;i<n;i++){
            unordered_set<int>odd,even;
            for(int j=i;j<n;j++){
                if(nums[j]%2){
                    odd.insert(nums[j]);
                }
                else {
                    even.insert(nums[j]);
                }
                if(odd.size()==even.size()){
                    longest=max(longest,j-i+1);

                }

            }
            odd.clear();
            even.clear();
        }
        return longest;
        
    }
};