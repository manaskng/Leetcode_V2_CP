class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        if(n==1) return 0;
        int acnt=0;
        int bcnt=0;
        vector<pair<int,int>>prefix(n);
        if(s[0]=='a') acnt++;
        else bcnt++;
        prefix[0]={acnt,bcnt};
        for(int i=1;i<n;i++){
            if(s[i]=='a') acnt++;
            else if(s[i]=='b') bcnt++;
            prefix[i]={acnt,bcnt};// no.of a's till i and no.of b's cnt till there 
        }
        // now we go for split at each array index and calculate what will be the amount of make the split first side a and next side b
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            // no. of b's in first side to remove and no.of a's in next side to remove after removing cnt which is already in first side
            mini=min(mini,prefix[i].second + (prefix[n-1].first-prefix[i].first));

        }
        mini=min(mini,prefix[n-1].first);
        mini=min(mini,prefix[n-1].second);
        return mini;

    }
};