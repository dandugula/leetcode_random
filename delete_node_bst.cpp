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

Node* findMinNode(Node* root)
{
  while(root->left != nullptr)
    root = root->left;
  return root;
}

Node* delete_node(Node* root, int i) {
  if(nullptr == root) return root;
  if(i < root->data) 
    root->left = delete_node(root->left, i);
  else if(i > root->data)
    root->right = delete_node(root->right, i);
  else {
    Node *tmp;
    if(nullptr == root->left) {
      tmp = root->right;
      delete root;
      return tmp;
    }
    if(nullptr == root->right) {
      tmp = root->left;
      delete root;
      return tmp;
    }
    tmp = findMinNode(root->right);
    root->data = tmp->data;
    root->right = delete_node(root->right, tmp->data);
  }  
  return root;
}

int main() {
  //std::vector<int> pre_order = {10, 5, 1, 7, 40, 50};
  std::vector<int> pre_order = {50, 30, 20, 40, 70, 60, 80};
  Node* root  = constructBST(pre_order);
  inOrder(root);
  std::cout << std::endl;
  root = delete_node(root, 20);
  inOrder(root);
  std::cout << std::endl;
  root = delete_node(root, 30);
  inOrder(root);
  std::cout << std::endl;
  //std::cout << std::endl;
  return 0;
}
