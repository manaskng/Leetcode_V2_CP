/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*f(int l, int h, vector<int>&nums){
        if(l>h) return nullptr;
        int mid=l+(h-l)/2;
        TreeNode*midi= new TreeNode(nums[mid]);
        // a node with middle value added 
        midi->left=f(l,mid-1,nums);
        midi->right=f(mid+1,h,nums);

        return midi;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return f(0,n-1,nums);
        
    }
};