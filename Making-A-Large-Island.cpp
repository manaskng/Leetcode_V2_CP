1class Solution {
2public:
3    vector<pair<int,int>> dirs = {{0,-1}, {-1,0}, {1,0}, {0,1}};
4
5    int dfs(int i, int j, vector<vector<int>>& grid, int id) {
6        int n = grid.size();
7        grid[i][j] = id;
8        int area = 1;
9
10        for (auto &dir : dirs) {
11            int ni = i + dir.first;
12            int nj = j + dir.second;
13
14            if (ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj] == 1) {
15                area += dfs(ni, nj, grid, id);
16            }
17        }
18        return area;
19    }
20
21    int largestIsland(vector<vector<int>>& grid) {
22        int n = grid.size();
23        unordered_map<int,int> area;
24        int id = 2;
25
26        // 🔥 Step 1: label islands
27        for (int i=0;i<n;i++) {
28            for (int j=0;j<n;j++) {
29                if (grid[i][j] == 1) {
30                    area[id] = dfs(i, j, grid, id);
31                    id++;
32                }
33            }
34        }
35
36        int ans = 0;
37
38        // 🚀 Step 2: try flipping 0
39        for (int i=0;i<n;i++) {
40            for (int j=0;j<n;j++) {
41                if (grid[i][j] == 0) {
42                    unordered_set<int> seen;
43                    int curr = 1;
44
45                    for (auto &dir : dirs) {
46                        int ni = i + dir.first;
47                        int nj = j + dir.second;
48
49                        if (ni>=0 && nj>=0 && ni<n && nj<n) {
50                            int nid = grid[ni][nj];
51                            if (nid > 1 && !seen.count(nid)) {
52                                curr += area[nid];
53                                seen.insert(nid);
54                            }
55                        }
56                    }
57
58                    ans = max(ans, curr);
59                }
60            }
61        }
62
63        // edge case: all 1s
64        if (ans == 0) return n*n;
65
66        return ans;
67    }
68};