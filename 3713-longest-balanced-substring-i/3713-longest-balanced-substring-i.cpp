class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int maxlen=1;
        for(int i=0;i<n;i++){
            int freq[26]={0};
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxi=0,mini=INT_MAX;

                for( int c=0;c<26;c++){
                    if(freq[c]>0){
                        mini=min(mini,freq[c]);
                        maxi=max(maxi,freq[c]);
                    }
                }
                if(mini==maxi&&mini!=INT_MAX){
                    maxlen=max(maxlen,j-i+1);
                    
                }
                
            }
        }
        return maxlen;
        
        
    }
};