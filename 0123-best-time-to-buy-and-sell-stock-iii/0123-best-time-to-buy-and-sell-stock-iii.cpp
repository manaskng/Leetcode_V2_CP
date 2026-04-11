class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=0;//maxprofit till this index from frontside
        int minele=prices[0];
        int preprofit=0;
        for(int i=1;i<n;i++){
            prefix[i]=max(preprofit,prices[i]-minele);
            minele=min(minele,prices[i]);
            preprofit=max(preprofit,prefix[i]);

        }
        suffix[n-1]=0;// maxprofit going from backside
        int postprofit=0;
        int maxele=prices[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(postprofit,maxele-prices[i]);
            maxele=max(maxele,prices[i]);
            postprofit=max(postprofit,suffix[i]);

        }
        int maxprofit=0;
        for(int i=0;i<n;i++){
            maxprofit=max(maxprofit,prefix[i]+suffix[i]);
        }
        return maxprofit;
        
        
    }
};