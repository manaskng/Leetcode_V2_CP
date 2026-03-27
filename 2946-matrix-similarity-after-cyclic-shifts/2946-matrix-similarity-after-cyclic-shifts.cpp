class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        k %= m;
        if (k == 0) return true;

        vector<vector<int>> shifted(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i % 2 == 0) {
                   
                    shifted[i][j] = mat[i][(j + k) % m];
                } else {
                    
                    shifted[i][j] = mat[i][(j - k + m) % m];
                }
            }
        }

        return shifted == mat;
    }
};