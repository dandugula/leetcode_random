/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
private:
    int max_depth(Node *root, int& depth) {
      if(nullptr == root) return 0;

      for(auto child : root->children) {
        depth = max(depth , max_depth(child, depth)) + 1;
      }
      return depth;
    }
public:
    int maxDepth(Node* root) {
      int max_depth = 0;
      maxDepth(root, max_depth);
      return max_depth;
    }
};
