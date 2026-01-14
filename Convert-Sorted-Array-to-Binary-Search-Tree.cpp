1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode*f(int l, int h, vector<int>&nums){
15        if(l>h) return nullptr;
16        int mid=l+(h-l)/2;
17        TreeNode*midi= new TreeNode(nums[mid]);
18        // a node with middle value added 
19        midi->left=f(l,mid-1,nums);
20        midi->right=f(mid+1,h,nums);
21
22        return midi;
23
24    }
25    TreeNode* sortedArrayToBST(vector<int>& nums) {
26        int n=nums.size();
27        return f(0,n-1,nums);
28        
29    }
30};