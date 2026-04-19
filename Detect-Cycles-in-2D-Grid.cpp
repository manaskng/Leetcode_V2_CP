1class Solution {
2public:
3int n,m;
4vector<pair<int,int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
5 bool dfs(int i, int j, int pi, int pj,
6         vector<vector<bool>>& vis,
7         vector<vector<char>>& grid) {
8
9    vis[i][j] = true;
10
11    for (auto dir : dirs) {
12        int ni = i + dir.first;
13        int nj = j + dir.second;
14
15        if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
16            grid[ni][nj] == grid[i][j]) {
17
18            if (!vis[ni][nj]) {
19                if (dfs(ni, nj, i, j, vis, grid)) {
20                    return true;
21                }
22            }
23            
24            else if (!(ni == pi && nj == pj)) {
25                return true;
26            }
27        }
28    }
29    return false;
30}
31    bool containsCycle(vector<vector<char>>& grid) {
32        n=grid.size();
33        m=grid[0].size();
34        vector<vector<bool>>vis(n,vector<bool>(m,false));
35        for(int i=0;i<n;i++){
36            for(int j=0;j<m;j++){
37                if(!vis[i][j]){
38                    if(dfs(i,j,-1,-1,vis,grid)==true) {
39                        return true;
40                    }
41
42                }
43            }
44        }
45        return false;
46        
47    }
48};