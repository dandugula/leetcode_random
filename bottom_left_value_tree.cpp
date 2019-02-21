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
  int findBottomLeftValue(TreeNode* root) {
    std::queue<TreeNode*> level;
    int h = height(root);
    TreeNode* tmp = nullptr;

    level.push(root);
    for(int i = h; i != 1; --i) {
      int s = level.size();
      while(s) {
        tmp = level.front();
        level.pop();
        if(nullptr != tmp->left) level.push(tmp->left);
        if(nullptr != tmp->right) level.push(tmp->right);
        --s;
      }
    }
    return level.front()->val;
  }
};
