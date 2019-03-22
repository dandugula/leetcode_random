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
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        if(!root->left && !root->right) return 1;

        int leftMin = root->left ? minDepth(root->left) : INT_MAX;
        int rightMin = root->right ? minDepth(root->right) : INT_MAX;

        return std::min(leftMin, rightMin) + 1;
    }
};
