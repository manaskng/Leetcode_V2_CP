class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        for(int i=0;i<n-1;i++){
            maxprofit+=(prices[i+1]>prices[i])?(prices[i+1]-prices[i]):0;
        }
        return maxprofit;
        
    }
};