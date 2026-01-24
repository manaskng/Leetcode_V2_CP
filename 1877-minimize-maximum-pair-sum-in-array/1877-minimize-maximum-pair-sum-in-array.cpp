class Solution {
public:
    bool check(int mid, vector<int>& nums, int n) {
        int i = 0, j = n - 1;
        while (i < j) {
            if (nums[i] + nums[j] > mid) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = nums[0] + nums[1];
        int h = nums[n - 1] + nums[n - 2];
        int ans = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, nums, n)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
