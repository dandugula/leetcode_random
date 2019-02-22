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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if(!nums.size()) return nullptr;

    auto maxNumber = std::max_element(nums.begin(), nums.end());
    TreeNode* root = new TreeNode(*maxNumber);

    std::vector<int> leftTree(nums.begin(), maxNumber);
    std::vector<int> rightTree(maxNumber + 1, nums.end());

    root->left = constructMaximumBinaryTree(leftTree);
    root->right = constructMaximumBinaryTree(rightTree);

    return root;
  }
};
