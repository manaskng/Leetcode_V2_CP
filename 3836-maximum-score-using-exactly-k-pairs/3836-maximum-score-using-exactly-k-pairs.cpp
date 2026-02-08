class Solution {
public:
    int n, m;
    vector<int> a, b;
    vector<vector<vector<long long>>> memo;
    vector<vector<vector<bool>>> vis;

    long long dfs(int i, int j, int t) {
        if (t == 0) return 0;
        if (i == n || j == m) return LLONG_MIN;
        if (n - i < t || m - j < t) return LLONG_MIN;

        if (vis[i][j][t]) return memo[i][j][t];
        vis[i][j][t] = true;

        long long res = LLONG_MIN;

     
        res = max(res, dfs(i + 1, j, t));

       
        res = max(res, dfs(i, j + 1, t));

    
        long long take = dfs(i + 1, j + 1, t - 1);
        if (take != LLONG_MIN) {
            take += 1LL * a[i] * b[j];
            res = max(res, take);
        }

        return memo[i][j][t] = res;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        a = nums1;
        b = nums2;
        n = a.size();
        m = b.size();

        memo.assign(n, vector<vector<long long>>(m, vector<long long>(k + 1)));
        vis.assign(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));

        return dfs(0, 0, k);
    }
};
