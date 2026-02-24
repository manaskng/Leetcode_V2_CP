class Solution {
public:
    void dfs(TreeNode* root, int curr, int &total) {
        if(!root) return;

        curr = (curr << 1) + root->val;

        if(!root->left && !root->right) {
            total += curr;
            return;
        }

        dfs(root->left, curr, total);
        dfs(root->right, curr, total);
    }

    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        dfs(root, 0, total);
        return total;
    }
};