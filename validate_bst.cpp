class Solution {
private:
  std::vector<int> in_order;
  void inOrder(TreeNode* root) {
    if(nullptr == root) return;

    inOrder(root->left);
    in_order.push_back(root->val);
    inOrder(root->right);
    
    return;
  }
public:
    bool isValidBST(TreeNode* root) {
      inOrder(root);

      for(int i = 1; i < in_order.size(); ++i) 
        if(in_order[i-1] > in_order[i]) return false;

      return true;
    }
};
