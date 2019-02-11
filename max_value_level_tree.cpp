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

  int height(TreeNode* root) {
    if(nullptr == root) return 0;
    return std::max(height(root->left), height(root->right)) + 1;
  }

public:

  vector<int> largestValues(TreeNode* root) {
    std::queue<TreeNode*> level;
    std::vector<int> res;
    int h = height(root);
    TreeNode* tmp = nullptr;
    if(0 != h) level.push(root);
    for(int i = 0; i < h; ++i) {
      int s = level.size();
      int max = INT_MIN;
      while(s) {
        tmp = level.front();
        level.pop();
        if(nullptr != tmp->left) level.push(tmp->left);
        if(nullptr != tmp->right) level.push(tmp->right);
        max = max < tmp->val ? tmp->val : max;
        --s;
      }
      res.push_back(max);
    }
    return res;
  }
};
