class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        int totalpossible=pow(2,k);
        unordered_set<string>st;
        for(int i=0;i<=n-k;i++){
            string sub= s.substr(i,k);
            if(!st.count(sub)){
                st.insert(sub);
            }


        }
        return st.size()==totalpossible;
        
    }
};