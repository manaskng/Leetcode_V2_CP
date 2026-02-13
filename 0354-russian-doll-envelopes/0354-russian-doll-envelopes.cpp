class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        int len=1;
        int maxifirst=envelopes[0][0],maxisec=envelopes[0][1];
        for(int i=0;i<n-1;i++){
            if(maxifirst<envelopes[i+1][0]&&maxisec<envelopes[i+1][1]){
                len++;
                maxifirst=envelopes[i+1][0];
                maxisec=envelopes[i+1][1];
            }
            // if next one first is equal and next one sec is must larger than we must leave no need to change it 
            // if next one first is bigger but next one sec is smaller then ? we need to decide which one to continue as a later element can be which bigger first and smaller sec then invalid to take 
            // else {
            //     maxifirst=min(maxifirst,envelopes[i+1][0]);
            //     maxisec=min(maxisec,envelopes[i+1][1]);
            // }
        }
        return len;
        
    }
};