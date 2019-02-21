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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      std::queue<TreeNode*> level_queue;
      std::vector<std::vector<int>> res;
      int level = 0;
      TreeNode* temp;

      if(nullptr != root)
        level_queue.push(root);

      while(!level_queue.empty()) {
        int size = level_queue.size();
        res.push_back(std::vector<int>());
        do {
          temp = level_queue.front();
          level_queue.pop();
          res[level].push_back(temp->val);
          if(temp->left != nullptr) level_queue.push(temp->left);
          if(temp->right != nullptr) level_queue.push(temp->right);
          --size;
        }while(0 != size);

        if(level % 2 == 1)
          std::reverse(std::begin(res[level]), std::end(res[level])); 

        ++level;
      }

    return res;
  }
};

