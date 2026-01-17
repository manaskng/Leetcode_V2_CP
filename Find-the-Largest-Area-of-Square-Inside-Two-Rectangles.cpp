1class Solution {
2public:
3    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
4        long long maxSide = 0;
5        int n = bottomLeft.size();
6
7        for (int i = 0; i < n; i++) {
8            for (int j = i + 1; j < n; j++) {
9                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
10                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
11                long long x2 = min(topRight[i][0], topRight[j][0]);
12                long long y2 = min(topRight[i][1], topRight[j][1]);
13                long long width = x2 - x1;
14                long long height = y2 - y1;
15
16                
17                if (width > 0 && height > 0) {
18                    long long currentSide = min(width, height);
19                    maxSide = max(maxSide, currentSide);
20                }
21            }
22        }
23
24        return maxSide * maxSide;
25    }
26};