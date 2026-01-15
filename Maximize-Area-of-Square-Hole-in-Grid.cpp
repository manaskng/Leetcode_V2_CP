1class Solution {
2public:
3    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
4        // we find the consecutive max streak in both and take min of that and do min+1's square
5        int lstreak=1;
6        int maxi=1;
7        sort(hBars.begin(),hBars.end());
8        sort(vBars.begin(),vBars.end());
9        int n1=hBars.size();
10        int m1=vBars.size();
11
12        for(int i=1;i<n1;i++){
13            if(hBars[i]==hBars[i-1]+1){
14                lstreak++;
15            }
16            else {
17                maxi=max(maxi,lstreak);
18                lstreak=1;
19                
20            }
21
22        }
23        maxi=max(maxi,lstreak);
24        int maxi2=1;
25        int hstreak=1;
26        for(int i=1;i<m1;i++){
27            if(vBars[i]==vBars[i-1]+1){
28                hstreak++;
29            }
30            else {
31                maxi2=max(maxi2,hstreak);
32                hstreak=1;
33                
34            }
35
36        }
37        maxi2=max(maxi2,hstreak);
38        int mini=min(maxi,maxi2)+1;
39        return mini*mini;
40        
41    }
42};