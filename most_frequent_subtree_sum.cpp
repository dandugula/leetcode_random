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
    int sumOfTree(TreeNode* root) {
        if(nullptr == root) return 0;
        return root->val + sumOfTree(root->left)
               + sumOfTree(root->right);
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        std::map<int, int> sum_freq;
        std::stack<TreeNode*> depth_stack;
        std::vector<std::pair<int, int>> sorted;
        std::vector<int> res;

        if(nullptr == root) return res;

        depth_stack.push(root);

        do {
            TreeNode* t = depth_stack.top();
            depth_stack.pop();

            int sum = t->val + sumOfTree(t->left) + sumOfTree(t->right);
            if(sum_freq.find(sum) == sum_freq.end())
                sum_freq.insert(std::make_pair(sum, 1));
            else
                sum_freq[sum]++;

            if(nullptr != t->left) depth_stack.push(t->left);
            if(nullptr != t->right) depth_stack.push(t->right);

        } while(!depth_stack.empty());

        std::copy(sum_freq.begin(), sum_freq.end(), std::back_inserter(sorted));
        std::sort(sorted.begin(), sorted.end(), [](auto l, auto r) {
                   if(l.second == r.second)
                    return l.first < r.first;
                   return l.second > r.second; 
                });

        int max_freq = -1; 
        
        for(int i = 0; i < sorted.size(); ++i) {
            if(max_freq > sorted[i].second) break; 
            res.push_back(sorted[i].first);
            max_freq = sorted[i].second;
        }

        return res;
    }
};
