1class Solution {
2public:
3    void inorder(TreeNode* root, vector<int>& sortedTree){
4        if(!root) return;
5        inorder(root->left, sortedTree);
6        sortedTree.push_back(root->val);
7        inorder(root->right, sortedTree);
8    }
9
10    TreeNode* BuildTree(int l, int h, vector<int>& sortedTree){
11        if(l > h) return nullptr;
12
13        int mid = l + (h-l)/2;
14        TreeNode* root = new TreeNode(sortedTree[mid]);
15
16        root->left  = BuildTree(l, mid-1, sortedTree);
17        root->right = BuildTree(mid+1, h, sortedTree);
18
19        return root;
20    }
21
22    TreeNode* balanceBST(TreeNode* root) {
23        vector<int> sortedTree;
24        inorder(root, sortedTree);
25
26        return BuildTree(0, sortedTree.size()-1, sortedTree);
27    }
28};
29