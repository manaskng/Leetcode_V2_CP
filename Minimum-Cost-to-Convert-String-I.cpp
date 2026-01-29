1class Solution {
2public:
3    long long minimumCost(string source, string target,
4 vector<char>& original, vector<char>& changed, vector<int>& cost) {
5        long long dist[26][26];
6        const long long INF = 1e14;
7
8        for (int i = 0; i < 26; ++i) {
9            for (int j = 0; j < 26; ++j) {
10                dist[i][j] = (i == j) ? 0 : INF;
11            }
12        }
13
14        for (size_t i = 0; i < original.size(); ++i) {
15            int u = original[i] - 'a';
16            int v = changed[i] - 'a';
17            dist[u][v] = min(dist[u][v], (long long)cost[i]);
18        }
19
20        for (int k = 0; k < 26; ++k) {
21            for (int i = 0; i < 26; ++i) {
22                if (dist[i][k] == INF) continue;
23                for (int j = 0; j < 26; ++j) {
24                    if (dist[k][j] != INF) {
25                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
26                    }
27                }
28            }
29        }
30
31        long long totalCost = 0;
32        int n = source.length();
33
34        for (int i = 0; i < n; ++i) {
35            int u = source[i] - 'a';
36            int v = target[i] - 'a';
37            if (u == v) continue;
38            if (dist[u][v] == INF) return -1;
39            totalCost += dist[u][v];
40        }
41
42        return totalCost;
43    }
44};