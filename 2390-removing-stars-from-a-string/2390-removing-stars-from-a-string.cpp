class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else {
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};