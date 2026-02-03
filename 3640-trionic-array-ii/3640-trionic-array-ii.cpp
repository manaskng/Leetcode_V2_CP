class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        nums.push_back(INT_MIN);

        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = nums[i] + prefix[i];
        }

        long long maxSum = -1e15;

        int prevIncIdx = -1;
        int currIncIdx = -1;
        bool isInc = false;

        for (int i = 0; i < n - 1; i++) {
            int currEle = nums[i];
            int nextEle = nums[i + 1];

            if (currEle < nextEle) {
            //Increasing Edge
                if (!isInc) {
                    isInc = true;
                    currIncIdx = i;
                }

                //Checking all possible sum
                if (prevIncIdx != -1) {
                    maxSum = max(maxSum, 
                    prefix[i + 2] - prefix[prevIncIdx]);
                }
            }
            else if (nextEle < currEle) {
            //Decreasing edge
                if (isInc) {
                    prevIncIdx = currIncIdx;
                }
                isInc = false;
            }
            else {
            //Equal Edge
                prevIncIdx = -1;
                isInc = false;
                currIncIdx = -1;
            }

            /* Moving Prev to better index while ensuring
            that the increasing sequence doesn't end*/
            while (
                prevIncIdx != -1 &&
                prevIncIdx + 2 < n &&
                nums[prevIncIdx + 1] < nums[prevIncIdx + 2] &&
                nums[prevIncIdx] < 0
            ) {
                prevIncIdx++;
            }
        }

        return maxSum;
    }
};