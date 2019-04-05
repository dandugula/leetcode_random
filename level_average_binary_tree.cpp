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
    vector<double> averageOfLevels(TreeNode* root) {
        std::queue<TreeNode*> level_queue;
        std::vector<double> res;
        int n_level_nodes = 1;

        level_queue.push(root);
        
        do {
            double sum = 0;
            int current_level_nodes = 0;

            for(int i = 0; i < n_level_nodes; ++i) {
                TreeNode* t = level_queue.front();

                level_queue.pop();
                sum += t->val;

                if(nullptr != t->left) { level_queue.push(t->left); ++current_level_nodes; }
                if(nullptr != t->right) { level_queue.push(t->right); ++current_level_nodes; }
            }

            res.push_back(sum / n_level_nodes);
            n_level_nodes = current_level_nodes;

        } while(!level_queue.empty()); 

        return res;
    }
};

