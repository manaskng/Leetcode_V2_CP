class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res = max(res, r - l + 2);
                l--; r++;
            }
            int sl = l - 1, sr = r;
            while (sl >= 0 && sr < n && s[sl] == s[sr]) {
                res = max(res, sr - sl + 1);
                sl--; sr++;
            }
            sl = l; sr = r + 1;
            while (sl >= 0 && sr < n && s[sl] == s[sr]) {
                res = max(res, sr - sl + 1);
                sl--; sr++;
            }
        }
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res = max(res, r - l + 2);
                l--; r++;
            }
            int sl = l - 1, sr = r;
            while (sl >= 0 && sr < n && s[sl] == s[sr]) {
                res = max(res, sr - sl + 1);
                sl--; sr++;
            }
            sl = l; sr = r + 1;
            while (sl >= 0 && sr < n && s[sl] == s[sr]) {
                res = max(res, sr - sl + 1);
                sl--; sr++;
            }
        }
        return min(res, n);
    }
};