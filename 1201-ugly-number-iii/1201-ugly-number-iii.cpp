class Solution {
public:
    long long gcd(long long x, long long y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }

    long long check(long long mid, int a, int b, int c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ac = lcm(a, c);
        long long abc = lcm(ab, c);

        return mid / a + mid / b + mid / c
             - mid / ab - mid / bc - mid / ac
             + mid / abc;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 1, h = 2e9;

        while (l < h) {
            long long mid = l + (h - l) / 2;
            if (check(mid, a, b, c) >= n)
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
