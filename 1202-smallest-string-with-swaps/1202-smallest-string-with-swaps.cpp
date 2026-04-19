class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> adj(n);

        for (auto &p : pairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(n, false);
        string ans = s;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            
            vector<int> comp;
            queue<int> q;
            q.push(i);
            vis[i] = true;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                comp.push_back(node);

                for (int nei : adj[node]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }

            // collect characters
            string chars = "";
            for (int idx : comp) chars += s[idx];

            sort(comp.begin(), comp.end());
            sort(chars.begin(), chars.end());

            // place back
            for (int j = 0; j < comp.size(); j++) {
                ans[comp[j]] = chars[j];
            }
        }

        return ans;
    }
};