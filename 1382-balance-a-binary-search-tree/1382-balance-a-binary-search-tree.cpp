class Solution {
public:
    void inorder(TreeNode* root, vector<int>& sortedTree){
        if(!root) return;
        inorder(root->left, sortedTree);
        sortedTree.push_back(root->val);
        inorder(root->right, sortedTree);
    }

    TreeNode* BuildTree(int l, int h, vector<int>& sortedTree){
        if(l > h) return nullptr;

        int mid = l + (h-l)/2;
        TreeNode* root = new TreeNode(sortedTree[mid]);

        root->left  = BuildTree(l, mid-1, sortedTree);
        root->right = BuildTree(mid+1, h, sortedTree);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedTree;
        inorder(root, sortedTree);

        return BuildTree(0, sortedTree.size()-1, sortedTree);
    }
};
