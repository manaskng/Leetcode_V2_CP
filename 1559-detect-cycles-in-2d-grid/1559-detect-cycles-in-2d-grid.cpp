class Solution {
public:
int n,m;
vector<pair<int,int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
 bool dfs(int i, int j, int pi, int pj,
         vector<vector<bool>>& vis,
         vector<vector<char>>& grid) {

    vis[i][j] = true;

    for (auto dir : dirs) {
        int ni = i + dir.first;
        int nj = j + dir.second;

        if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
            grid[ni][nj] == grid[i][j]) {

            if (!vis[ni][nj]) {
                if (dfs(ni, nj, i, j, vis, grid)) {
                    return true;
                }
            }
            
            else if (!(ni == pi && nj == pj)) {
                return true;
            }
        }
    }
    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,vis,grid)==true) {
                        return true;
                    }

                }
            }
        }
        return false;
        
    }
};