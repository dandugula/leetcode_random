#include <iostream>
#include <stack>
#include <vector>

struct Node {
  int data;
  Node* left, *right;
  Node(int d = 0):data(d), left(nullptr), right(nullptr) {}
};

Node* constructBST(const std::vector<int>& pre_order) {
  std::stack<Node*> temp;
  Node* root = new Node(pre_order[0]);
  temp.push(root);

  for(int i = 1; i < pre_order.size(); ++i) {
    Node* tmp = nullptr;
    while(!temp.empty() && pre_order[i] > temp.top()->data)
      tmp = temp.top(), temp.pop();

    if(nullptr == tmp) {
      tmp = temp.top();
      tmp->left = new Node(pre_order[i]);
      temp.push(tmp->left);
    } else {
      tmp->right = new Node(pre_order[i]);
      temp.push(tmp->right);
    }
  }
  return root;
}
void inOrder(Node* root) {
  if(nullptr == root) {
    return;
  }
  inOrder(root->left);
  std::cout << root->data << " ";
  inOrder(root->right);
}

int main() {
  //std::vector<int> pre_order = {10, 5, 1, 7, 40, 50};
  std::vector<int> pre_order = {5, 3, 1, 4, 9, 6};
  Node* root  = constructBST(pre_order);
  inOrder(root);
  std::cout << std::endl;
  return 0;
}
