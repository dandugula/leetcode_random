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
    vector<int> preorderTraversal(TreeNode* root) {
      std::stack<TreeNode*> cache;
      std::vector<int> res;
      if(nullptr != root)
        cache.push(root);
      while(!cache.empty()) {
        TreeNode* tmp = cache.top();
        cache.pop();
        res.push_back(tmp->val);
        if(nullptr != tmp->right) cache.push(tmp->right);
        if(nullptr != tmp->left) cache.push(tmp->left);
      }
      return res;
    }
};
