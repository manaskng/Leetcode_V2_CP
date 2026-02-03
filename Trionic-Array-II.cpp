1class Solution {
2public:
3    long long maxSumTrionic(vector<int>& nums) {
4        nums.push_back(INT_MIN);
5
6        int n = nums.size();
7        vector<long long> prefix(n + 1, 0);
8
9        for (int i = 0; i < n; i++) {
10            prefix[i + 1] = nums[i] + prefix[i];
11        }
12
13        long long maxSum = -1e15;
14
15        int prevIncIdx = -1;
16        int currIncIdx = -1;
17        bool isInc = false;
18
19        for (int i = 0; i < n - 1; i++) {
20            int currEle = nums[i];
21            int nextEle = nums[i + 1];
22
23            if (currEle < nextEle) {
24            //Increasing Edge
25                if (!isInc) {
26                    isInc = true;
27                    currIncIdx = i;
28                }
29
30                //Checking all possible sum
31                if (prevIncIdx != -1) {
32                    maxSum = max(maxSum, 
33                    prefix[i + 2] - prefix[prevIncIdx]);
34                }
35            }
36            else if (nextEle < currEle) {
37            //Decreasing edge
38                if (isInc) {
39                    prevIncIdx = currIncIdx;
40                }
41                isInc = false;
42            }
43            else {
44            //Equal Edge
45                prevIncIdx = -1;
46                isInc = false;
47                currIncIdx = -1;
48            }
49
50            /* Moving Prev to better index while ensuring
51            that the increasing sequence doesn't end*/
52            while (
53                prevIncIdx != -1 &&
54                prevIncIdx + 2 < n &&
55                nums[prevIncIdx + 1] < nums[prevIncIdx + 2] &&
56                nums[prevIncIdx] < 0
57            ) {
58                prevIncIdx++;
59            }
60        }
61
62        return maxSum;
63    }
64};