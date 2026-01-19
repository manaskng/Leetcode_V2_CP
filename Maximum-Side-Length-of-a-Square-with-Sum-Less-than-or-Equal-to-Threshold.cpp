1class Solution {
2public:
3    bool check(int mid,
4               vector<vector<long long>>& prefix,
5               int n, int m, int threshold) {
6
7        for(int i = 0; i + mid <= n; i++){
8            for(int j = 0; j + mid <= m; j++){
9                int br = i + mid;
10                int bc = j + mid;
11
12                long long sum =
13                    prefix[br][bc]
14                  - prefix[i][bc]
15                  - prefix[br][j]
16                  + prefix[i][j];
17
18                if(sum <= threshold)
19                    return true;
20            }
21        }
22        return false;
23    }
24
25    int maxSideLength(vector<vector<int>>& mat, int threshold) {
26        int n = mat.size();
27        int m = mat[0].size();
28
29        vector<vector<long long>> prefix(n+1, vector<long long>(m+1, 0));
30
31        // build prefix sum (1-based)
32        for(int i = 1; i <= n; i++){
33            for(int j = 1; j <= m; j++){
34                prefix[i][j] =
35                    prefix[i-1][j]
36                  + prefix[i][j-1]
37                  - prefix[i-1][j-1]
38                  + mat[i-1][j-1];
39            }
40        }
41
42        int l = 0, h = min(n, m), ans = 0;
43
44        while(l <= h){
45            int mid = l + (h - l) / 2;
46
47            if(check(mid, prefix, n, m, threshold)){
48                ans = mid;
49                l = mid + 1;
50            } else {
51                h = mid - 1;
52            }
53        }
54        return ans;
55    }
56};
57