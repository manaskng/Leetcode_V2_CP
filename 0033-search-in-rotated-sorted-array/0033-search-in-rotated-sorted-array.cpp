class Solution {
public:
    int findRotationIndex(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1; // Rotation is to the right
            } else {
                high = mid; // Rotation is at mid or to the left
            }
        }
        return low; // Index of smallest element (rotation index)
    }

    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int rot = findRotationIndex(nums);

        // If not rotated
        if (rot == 0) {
            return binarySearch(nums, 0, n - 1, target);
        }

        if (target >= nums[0] && target <= nums[rot - 1]) {
            return binarySearch(nums, 0, rot - 1, target);
        } else {
            return binarySearch(nums, rot, n - 1, target);
        }
    }
};