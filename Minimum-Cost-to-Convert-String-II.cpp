1class Solution {
2public:
3    void dijkstra(int src, vector<vector<pair<int,int>>>& adj,
4                  vector<vector<long long>>& dist) {
5
6        priority_queue<pair<long long,int>,
7                       vector<pair<long long,int>>,
8                       greater<>> pq;
9
10        dist[src][src] = 0;
11        pq.push({0, src});
12
13        while (!pq.empty()) {
14            auto [d, u] = pq.top();
15            pq.pop();
16
17            if (d > dist[src][u]) continue;
18
19            for (auto &[v, w] : adj[u]) {
20                if (dist[src][v] > d + w) {
21                    dist[src][v] = d + w;
22                    pq.push({dist[src][v], v});
23                }
24            }
25        }
26    }
27
28    long long minimumCost(string source, string target,
29                          vector<string>& original,
30                          vector<string>& changed,
31                          vector<int>& cost) {
32
33       
34        unordered_map<string,int> mp;
35        int id = 0;
36        for (int i = 0; i < original.size(); i++) {
37            if (!mp.count(original[i])) mp[original[i]] = id++;
38            if (!mp.count(changed[i]))  mp[changed[i]]  = id++;
39        }
40
41     
42        vector<vector<pair<int,int>>> adj(id);
43        for (int i = 0; i < original.size(); i++) {
44            int u = mp[original[i]];
45            int v = mp[changed[i]];
46            adj[u].push_back({v, cost[i]});
47        }
48
49       
50        vector<vector<long long>> dist(id, vector<long long>(id, 1e18));
51        for (int i = 0; i < id; i++) {
52            dijkstra(i, adj, dist);
53        }
54
55        
56        unordered_set<int> lens;
57        for (auto &s : original) lens.insert(s.size());
58
59        int n = source.size();
60        vector<long long> dp(n + 1, 1e18);
61        dp[n] = 0;
62
63        // ---- DP ----
64        for (int i = n - 1; i >= 0; i--) {
65
66            // Case 1: no operation
67            if (source[i] == target[i]) {
68                dp[i] = dp[i + 1];
69            }
70
71            // Case 2: substring conversions
72            for (int len : lens) {
73                int j = i + len - 1;
74                if (j >= n) continue;
75
76                string from = source.substr(i, len);
77                string to   = target.substr(i, len);
78
79                if (!mp.count(from) || !mp.count(to)) continue;
80
81                long long c = dist[mp[from]][mp[to]];
82                if (c < 1e18) {
83                    dp[i] = min(dp[i], c + dp[j + 1]);
84                }
85            }
86        }
87
88        return dp[0] >= 1e18 ? -1 : dp[0];
89    }
90};