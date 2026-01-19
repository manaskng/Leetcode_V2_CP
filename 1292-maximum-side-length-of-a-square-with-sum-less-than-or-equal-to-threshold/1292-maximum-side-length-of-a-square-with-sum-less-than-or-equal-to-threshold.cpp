class Solution {
public:
    bool check(int mid,
               vector<vector<long long>>& prefix,
               int n, int m, int threshold) {

        for(int i = 0; i + mid <= n; i++){
            for(int j = 0; j + mid <= m; j++){
                int br = i + mid;
                int bc = j + mid;

                long long sum =
                    prefix[br][bc]
                  - prefix[i][bc]
                  - prefix[br][j]
                  + prefix[i][j];

                if(sum <= threshold)
                    return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<long long>> prefix(n+1, vector<long long>(m+1, 0));

        // build prefix sum (1-based)
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] =
                    prefix[i-1][j]
                  + prefix[i][j-1]
                  - prefix[i-1][j-1]
                  + mat[i-1][j-1];
            }
        }

        int l = 0, h = min(n, m), ans = 0;

        while(l <= h){
            int mid = l + (h - l) / 2;

            if(check(mid, prefix, n, m, threshold)){
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};
