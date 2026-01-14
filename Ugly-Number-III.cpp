1class Solution {
2public:
3    long long gcd(long long x, long long y) {
4        return y == 0 ? x : gcd(y, x % y);
5    }
6
7    long long lcm(long long x, long long y) {
8        return x / gcd(x, y) * y;
9    }
10
11    long long check(long long mid, int a, int b, int c) {
12        long long ab = lcm(a, b);
13        long long bc = lcm(b, c);
14        long long ac = lcm(a, c);
15        long long abc = lcm(ab, c);
16
17        return mid / a + mid / b + mid / c
18             - mid / ab - mid / bc - mid / ac
19             + mid / abc;
20    }
21
22    int nthUglyNumber(int n, int a, int b, int c) {
23        long long l = 1, h = 2e9;
24
25        while (l < h) {
26            long long mid = l + (h - l) / 2;
27            if (check(mid, a, b, c) >= n)
28                h = mid;
29            else
30                l = mid + 1;
31        }
32        return l;
33    }
34};
35