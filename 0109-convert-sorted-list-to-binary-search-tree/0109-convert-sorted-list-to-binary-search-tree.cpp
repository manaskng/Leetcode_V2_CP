/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* f(int l, int h, vector<int>& nums) {
        if (l > h) return nullptr;

        int mid = l + (h - l) / 2;
        TreeNode* midi = new TreeNode(nums[mid]);

        midi->left = f(l, mid - 1, nums);
        midi->right = f(mid + 1, h, nums);

        return midi;
    }
    TreeNode* sortedListToBST(ListNode* head) {
      ListNode*head1=head;
      vector<int>v;
      while(head1!=nullptr){
        v.push_back(head1->val);
        head1=head1->next;

      }
      int n=v.size();
      // calling the func to convert to array 
      return f(0, n - 1, v);
        
    }
};