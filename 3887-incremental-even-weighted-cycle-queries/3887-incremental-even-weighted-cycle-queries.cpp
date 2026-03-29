class Solution {
    vector<int> parent, rnk, dist;
    
    pair<int,int> find(int x) {
        if (parent[x] == x) return {x, 0};
        auto [r, d] = find(parent[x]);
        parent[x] = r;
        dist[x] ^= d;
        return {r, dist[x]};
    }
    
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rnk.assign(n, 0);
        dist.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        int count = 0;
        
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            
            auto [ru, du] = find(u);
            auto [rv, dv] = find(v);
            
            if (ru == rv) {
                // Same component - check if valid
                if ((du ^ dv) == w) count++;
            } else {
                // Different components - always valid, merge
                if (rnk[ru] < rnk[rv]) {
                    swap(ru, rv);
                    swap(du, dv);
                }
                parent[rv] = ru;
                dist[rv] = du ^ dv ^ w;
                if (rnk[ru] == rnk[rv]) rnk[ru]++;
                count++;
            }
        }
        
        return count;
    }
};