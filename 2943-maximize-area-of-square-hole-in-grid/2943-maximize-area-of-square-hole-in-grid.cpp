class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // we find the consecutive max streak in both and take min of that and do min+1's square
        int lstreak=1;
        int maxi=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int n1=hBars.size();
        int m1=vBars.size();

        for(int i=1;i<n1;i++){
            if(hBars[i]==hBars[i-1]+1){
                lstreak++;
            }
            else {
                maxi=max(maxi,lstreak);
                lstreak=1;
                
            }

        }
        maxi=max(maxi,lstreak);
        int maxi2=1;
        int hstreak=1;
        for(int i=1;i<m1;i++){
            if(vBars[i]==vBars[i-1]+1){
                hstreak++;
            }
            else {
                maxi2=max(maxi2,hstreak);
                hstreak=1;
                
            }

        }
        maxi2=max(maxi2,hstreak);
        int mini=min(maxi,maxi2)+1;
        return mini*mini;
        
    }
};