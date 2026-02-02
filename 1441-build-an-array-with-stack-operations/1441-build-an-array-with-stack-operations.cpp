class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int l = target.size();
        vector<string> ans;
        if (target[0] != 1) {
            int cnt = target[0] - 1;
            for (int i = 0; i < cnt; i++) {
                ans.push_back("Push");
            }
            for (int i = 0; i < cnt; i++) {
                ans.push_back("Pop");
            }
        }
        ans.push_back("Push");
        for (int i = 1; i < l; i++) {
            int d = target[i] - target[i - 1] - 1;
            if (d != 0) {
                for (int i = 0; i < d; i++) {
                    ans.push_back("Push");
                }
                for (int i = 0; i < d; i++) {
                    ans.push_back("Pop");
                }
            }
            ans.push_back("Push");
        }
        return ans;
    }
};