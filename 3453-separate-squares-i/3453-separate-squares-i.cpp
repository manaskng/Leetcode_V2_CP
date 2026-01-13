class Solution {
public:
    double target;

    double belowArea(double mid, vector<vector<int>>& squares) {
        double area = 0;
        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];

            if (mid <= y) {
                // nothing below
            }
            else if (mid >= y + l) {
                area += l * l;
            }
            else {
                area += (mid - y) * l;
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = -1e18;

        for (auto &sq : squares) {
            total += 1.0 * sq[2] * sq[2];
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1] + sq[2]));
        }

        target = total / 2.0;

        double eps = 1e-6;
        while (high - low > eps) {
            double mid = (low + high) / 2;
            if (belowArea(mid, squares) >= target)
                high = mid;
            else
                low = mid;
        }

        return low;
    }
};
