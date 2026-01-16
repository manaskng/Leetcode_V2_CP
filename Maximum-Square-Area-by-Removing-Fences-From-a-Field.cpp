1class Solution {
2public:
3const long long MOD = 1e9 + 7;
4    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
5        hFences.push_back(1);
6        hFences.push_back(m);
7        vFences.push_back(1);
8        vFences.push_back(n);
9
10        sort(hFences.begin(), hFences.end());
11        sort(vFences.begin(), vFences.end());
12
13        unordered_set<long long> H;
14
15
16        for (int i = 0; i < hFences.size(); i++) {
17            for (int j = i + 1; j < hFences.size(); j++) {
18                H.insert(hFences[j] - hFences[i]);
19            }
20        }
21
22        long long ans = -1;
23        for (int i = 0; i < vFences.size(); i++) {
24            for (int j = i + 1; j < vFences.size(); j++) {
25                long long d = vFences[j] - vFences[i];
26                if (H.count(d)) {
27                    ans = max(ans, d);
28                }
29            }
30        }
31
32        if (ans == -1) return -1;
33        return (ans * ans) % MOD;
34    }
35};
36