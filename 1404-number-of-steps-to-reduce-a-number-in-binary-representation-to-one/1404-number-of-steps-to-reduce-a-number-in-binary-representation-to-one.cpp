class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int ans = 0;
        int carry = 0;

        for(int i = n - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if(bit % 2 == 0) {
               
                ans += 1;
            } else {
               
                ans += 2;
                carry = 1;
            }
        }

        return ans + carry;
    }
};