class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd = nums[0], result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) 
            swap(maxProd, minProd); // Swap max and min if nums[i] is negative

        maxProd = max(nums[i], maxProd * nums[i]); // Update max product
        minProd = min(nums[i], minProd * nums[i]); // Update min product

        result = max(result, maxProd); // Update result
    }

    return result;
        
    }
};