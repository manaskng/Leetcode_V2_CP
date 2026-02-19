class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int cnt0=0;
        int cnt1=0;
        int totalcnt=0;
        if(s[0]=='0') cnt0++;
        else cnt1++;
        for(int i=1;i<n;i++){
            if(s[i-1]==s[i]&&s[i]=='0')cnt0++;
            if(s[i-1]==s[i]&&s[i]=='1')cnt1++;
            if(s[i-1]!=s[i]&&s[i]=='0'){
                // now new zero cnt we check if prev1's had something common with prev cnt0
                 
                 totalcnt+=min(cnt1,cnt0);// min of both 
                 cnt0=1;// redoing cntofzeros then
            }
            if(s[i-1]!=s[i]&&s[i]=='1'){
                 
                 totalcnt+=min(cnt1,cnt0);
                 cnt1=1;
            }
            
        }
        totalcnt+=min(cnt1,cnt0);
        return totalcnt;
        
    }
};