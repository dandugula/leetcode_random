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
  vector<int> postorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> dfs;
    std::vector<int> res;

    if(nullptr != root)
      dfs.push(root);

    while(!dfs.empty()){ 
      TreeNode* top = dfs.top();

      if(nullptr == top->left && nullptr == top->right) {
        res.push_back(top->val);
        dfs.pop();

      } else {
        if(nullptr != top->right) {
          dfs.push(top->right);
          top->right = nullptr;
        }

        if(nullptr != top->left) { 
          dfs.push(top->left);
          top->left = nullptr;
        }

      }
    }

    return res;
  }
};
