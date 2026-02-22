class Solution {
public:
    string maximumXor(string s, string t) {
        string ans = "";
        int n = s.size();

        int cnt0t = 0;
        int cnt1t = 0;

        for(int i = 0; i < n; i++){
            if(t[i] == '0') cnt0t++;
            else cnt1t++;
        }

        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(cnt1t){
                    ans += "1";
                    cnt1t--;
                }
                else {
                    ans += "0";
                }
            }
            else {
                if(cnt0t){
                    ans += "1";
                    cnt0t--;
                }
                else {
                    ans += "0";
                }
            }
        }

        return ans;
    }
};