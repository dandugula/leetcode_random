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
    TreeNode * pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->left  = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root && !root->left && 
            !root->right && 0 == root->val) {
            //With this the runtime = 8ms otherwise its 4ms.
            //delete root;
            return nullptr;
        }

        return root;
    }
};