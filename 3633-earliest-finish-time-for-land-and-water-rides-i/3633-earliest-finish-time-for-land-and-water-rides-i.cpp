class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
         
                int landStart = landStartTime[i];
                int landEnd = landStart + landDuration[i];
                int waterStart = max(waterStartTime[j], landEnd);
                int waterEnd = waterStart + waterDuration[j];
                ans = min(ans, waterEnd);

                int wStart = waterStartTime[j];
                int wEnd = wStart + waterDuration[j];
                int lStart = max(landStartTime[i], wEnd);
                int lEnd = lStart + landDuration[i];
                ans = min(ans, lEnd);
            }
        }
        return ans;
    }
};