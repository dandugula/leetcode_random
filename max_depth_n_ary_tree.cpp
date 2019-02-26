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
public:
  int maxDepth(Node* root) {
    if(nullptr == root) return 0;

    int max_depth = 0;

    for(auto aChild : root->children) {
      int t = maxDepth(aChild);

      if(max_depth < t)
        max_depth = t ;
    }

    return max_depth + 1;
  }
};
