class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int>indegree(n,0);
        for(int i=0;i<m;i++){
            int u=edges[i][0],v=edges[i][1];
            indegree[v]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }
        if(ans.size()>1) return -1;
        return ans[0];
        
    }
};