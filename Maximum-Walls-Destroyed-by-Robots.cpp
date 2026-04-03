1class Solution {
2public:
3    int maxWalls(vector<int>& robots, vector<int>& distance,
4                 vector<int>& walls) {
5        int n = robots.size();
6        int pos1, pos2, pos3, leftPos, rightPos;
7        vector<int> left(n, 0), right(n, 0), num(n, 0);
8        unordered_map<int, int> robotsToDistance;
9        for (int i = 0; i < n; i++) {
10            robotsToDistance[robots[i]] = distance[i];
11        }
12        sort(robots.begin(), robots.end());
13        sort(walls.begin(), walls.end());
14        for (int i = 0; i < n; i++) {
15            pos1 = upper_bound(walls.begin(), walls.end(), robots[i]) -
16                   walls.begin();
17            if (i >= 1) {
18                leftPos =
19                    lower_bound(walls.begin(), walls.end(),
20                                max(robots[i] - robotsToDistance[robots[i]],
21                                    robots[i - 1] + 1)) -
22                    walls.begin();
23            } else {
24                leftPos = lower_bound(walls.begin(), walls.end(),
25                                      robots[i] - robotsToDistance[robots[i]]) -
26                          walls.begin();
27            }
28            left[i] = pos1 - leftPos;
29            if (i < n - 1) {
30                rightPos =
31                    upper_bound(walls.begin(), walls.end(),
32                                min(robots[i] + robotsToDistance[robots[i]],
33                                    robots[i + 1] - 1)) -
34                    walls.begin();
35            } else {
36                rightPos =
37                    upper_bound(walls.begin(), walls.end(),
38                                robots[i] + robotsToDistance[robots[i]]) -
39                    walls.begin();
40            }
41            pos2 = lower_bound(walls.begin(), walls.end(), robots[i]) -
42                   walls.begin();
43            right[i] = rightPos - pos2;
44            if (i == 0) {
45                continue;
46            }
47            pos3 = lower_bound(walls.begin(), walls.end(), robots[i - 1]) -
48                   walls.begin();
49            num[i] = pos1 - pos3;
50        }
51        int subLeft, subRight, currentLeft, currentRight;
52        subLeft = left[0];
53        subRight = right[0];
54        for (int i = 1; i < n; i++) {
55            currentLeft =
56                max(subLeft + left[i], subRight - right[i - 1] +
57                                           min(left[i] + right[i - 1], num[i]));
58            currentRight = max(subLeft + right[i], subRight + right[i]);
59            subLeft = currentLeft;
60            subRight = currentRight;
61        }
62        return max(subLeft, subRight);
63    }
64};