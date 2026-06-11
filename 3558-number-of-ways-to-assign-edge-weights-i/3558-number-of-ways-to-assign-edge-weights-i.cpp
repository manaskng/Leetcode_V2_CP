class Solution {
public:
    const int mod=1e9+7;

    long long  expo(long long base , int exp){
        long long  ans=1;
        while(exp){
            if(exp&1) ans= (ans*base)%mod;
            base= (base*base)%mod;
            exp>>=1;
        }
        return ans;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int len=edges.size();
        int n=len+1;

        vector<vector<int>>adj(n+1);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>>q;
        vector<int>visited(n+1, 0);
        q.push({0,1});// pushing one with 0
        visited[1]=1;
        int maxdepth=0;
        while(!q.empty()){
            auto [dist, node]=q.front();q.pop();
            maxdepth=max(maxdepth,dist);
            for(auto nei: adj[node]){
                if(!visited[nei]){
                    visited[nei]=1;
                    q.push({dist+1, nei});
                }
            }
        }

        return expo(2, maxdepth-1);

        
    }
};