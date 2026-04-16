1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4        int n = queries.size(), sz = nums.size();
5        unordered_map<int, vector<int>> indices;
6        for (int i = 0; i < nums.size(); i++){
7            indices[nums[i]].push_back(i);
8        }
9        for (auto& pair : indices){
10            auto arr = pair.second;
11            int m = arr.size();
12            if (m == 1){
13                nums[arr[0]] = -1;
14                continue;
15            }
16            for (int i = 0; i < m; i++){
17                int f = arr[(i + 1) % m], b = arr[(i - 1 + m) % m];
18                int forward = min(sz - arr[i] + f, abs(arr[i] - f));
19                int backward = min(abs(b - arr[i]), arr[i] + sz - b);
20                nums[arr[i]] = min(backward, forward);
21            }
22        }
23        for (int i = 0; i < n; i++)
24            queries[i] = nums[queries[i]];
25        return queries;
26    }
27};