1class Solution {
2public:
3 typedef long long ll;
4    int minimumPairRemoval(vector<int>& nums) {
5        vector<ll> arr(nums.begin(), nums.end());
6        ll n = arr.size();
7        ll bad = 0;
8        vector<ll> prevIndex(n, 0), nextIndex(n, 0);
9        set<pair<ll, ll>> st;
10        for (int i = 0; i < n; i++) {
11            prevIndex[i] = i - 1;
12            nextIndex[i] = i + 1;
13            if (i > 0) {
14                if (arr[i] < arr[i - 1]) {
15                    bad++;
16                }
17                st.insert({arr[i] + arr[i - 1], i - 1});
18            }
19        }
20        ll ans = 0;
21        while (bad > 0) {
22            if (st.empty()) {
23                break;
24            }
25            auto [sum, firstIndex] = *st.begin();
26            st.erase(st.begin());
27            ll secondIndex = nextIndex[firstIndex];
28            ll firstLeft = prevIndex[firstIndex];
29            // if (firstIndex >= 0) {
30            //     firstLeft = prevIndex[firstIndex];
31            // }
32            ll secondRight = nextIndex[secondIndex];
33            // if (secondIndex < n) {
34            //     secondRight = nextIndex[secondIndex];
35            // }
36            if (firstLeft >= 0) {
37                auto it = st.find(
38                    {(ll)arr[firstLeft] + (ll)arr[firstIndex], firstLeft});
39                if (it != st.end()) {
40                    st.erase(it);
41                }
42
43                st.insert({(ll)arr[firstLeft] + sum, firstLeft});
44            }
45            if (secondRight < n) {
46                auto it = st.find(
47                    {(ll)arr[secondIndex] + (ll)arr[secondRight], secondIndex});
48                if (it != st.end()) {
49                    st.erase(it);
50                }
51                st.insert({(ll)arr[secondRight] + sum, firstIndex});
52            }
53
54            if (firstLeft >= 0 && arr[firstIndex] < arr[firstLeft]) {
55                bad--;
56            }
57
58            if (arr[secondIndex] < arr[firstIndex]) {
59                bad--;
60            }
61            if (secondRight < n && arr[secondRight] < arr[secondIndex]) {
62                bad--;
63            }
64
65            if (firstLeft >= 0 && sum < arr[firstLeft]) {
66                bad++;
67            }
68            if (secondRight < n && arr[secondRight] < sum) {
69                bad++;
70            }
71
72            arr[firstIndex] = sum;
73            nextIndex[firstIndex] = secondRight;
74            if (secondRight < n) {
75                prevIndex[secondRight] = firstIndex;
76            }
77
78            ans++;
79        }
80        return ans;
81    }
82};