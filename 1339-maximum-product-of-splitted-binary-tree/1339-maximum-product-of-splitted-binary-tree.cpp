class Solution {
public:
    long long sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }

    long long rec(TreeNode* root, long long& maxi, long long totalSum) {
        if (!root) return 0;

        long long left = rec(root->left, maxi, totalSum);
        long long right = rec(root->right, maxi, totalSum);

        long long curr = root->val + left + right;

        long long product = curr * (totalSum - curr);
        maxi = max(maxi, product);

        return curr;
    }

    int maxProduct(TreeNode* root) {
        long long totalSum = sum(root);
        long long maxi = 0;

        rec(root, maxi, totalSum);

        return maxi % 1000000007;
    }
};
