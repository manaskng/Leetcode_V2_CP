1class Solution {
2public:
3    multiset<long long> small, large;
4    long long sumSmall = 0;
5    int need;
6
7    void rebalance() {
8        while ((int)small.size() > need) {
9            auto it = prev(small.end()); 
10            sumSmall -= *it;
11            large.insert(*it);
12            small.erase(it);
13        }
14
15        while ((int)small.size() < need && !large.empty()) {
16            auto it = large.begin();  
17            sumSmall += *it;
18            small.insert(*it);
19            large.erase(it);
20        }
21    }
22
23    void add(long long x) {
24        if (small.empty() || x <= *small.rbegin()) {
25            small.insert(x);
26            sumSmall += x;
27        } else {
28            large.insert(x);
29        }
30        rebalance();
31    }
32
33    void remove(long long x) {
34        if (small.find(x) != small.end()) {
35            small.erase(small.find(x));
36            sumSmall -= x;
37        } else {
38            large.erase(large.find(x));
39        }
40        rebalance();
41    }
42
43    long long minimumCost(vector<int>& nums, int k, int dist) {
44        int n = nums.size();
45        need = k - 1;
46
47       
48        for (int i = 1; i <= dist + 1; i++) {
49            add(nums[i]);
50        }
51
52        long long ans = sumSmall;
53
54        for (int r = dist + 2; r < n; r++) {
55            add(nums[r]);
56            remove(nums[r - (dist + 1)]);
57            ans = min(ans, sumSmall);
58        }
59
60        return nums[0] + ans;
61    }
62};
63