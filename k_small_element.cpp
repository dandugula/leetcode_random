/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
private:
    int kth_smallest = -1;
    int count = 0;

    void findKthSmallest(TreeNode* root, int k) {
        if (nullptr == root) return;

        if (kth_smallest == -1) {
            findKthSmallest(root->left, k);
            ++count;
            if (count == k) kth_smallest = root->val;
            findKthSmallest(root->right, k);
        }
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
       findKthSmallest(root, k);

       return kth_smallest;
    }
};