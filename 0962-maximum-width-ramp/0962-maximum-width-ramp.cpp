class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;

        // step 1: decreasing stack
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }

        int mx = 0;

        // step 2: scan from right
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                mx = max(mx, j - st.top());
                st.pop();
            }
        }

        return mx;
    }
};
