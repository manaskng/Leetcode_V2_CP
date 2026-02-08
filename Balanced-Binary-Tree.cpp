1class Solution {
2public:
3    
4    int check(TreeNode* root) {
5        if (!root) return 0;
6
7        int left = check(root->left);
8        if (left == -1) return -1;
9
10        int right = check(root->right);
11        if (right == -1) return -1;
12
13        if (abs(left - right) > 1) return -1;
14
15        return max(left, right) + 1;
16    }
17
18    bool isBalanced(TreeNode* root) {
19        return check(root) != -1;
20    }
21};