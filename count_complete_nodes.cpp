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
  int countNodes(TreeNode* root) {
    std::queue<TreeNode*> level;
    int c = 0;
    int h = height(root);
    TreeNode* tmp = nullptr;

    if(0 != h) level.push(root);
    
    for(int i = 0; i < h; ++i) {
      int s = level.size();
      c += s;
      while(s) {
        tmp = level.front();
        level.pop();
        if(nullptr != tmp->left) level.push(tmp->left);
        if(nullptr != tmp->right) level.push(tmp->right);
        --s;
      }
    }

    return c;

  }
};
