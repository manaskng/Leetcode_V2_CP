class Solution {
public:
    int mirrorFrequency(string s) {
        int charf[26] = {0};
        int digf[10] = {0};

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                charf[s[i] - 'a']++;
            } else {
                digf[s[i] - '0']++;
            }
        }

        int res = 0;

        for(int i = 0; i < 13; i++){
            res += abs(charf[i] - charf[25 - i]);
        }

        for(int i = 0; i < 5; i++){
            res += abs(digf[i] - digf[9 - i]);
        }

        return res;
        
    }
};