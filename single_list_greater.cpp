#include <vector>
#include <iostream>
#include <stack>

struct Node {
  int data;
  Node *next, *greater;
  Node(int d = 0) : data(d), next(nullptr), greater(nullptr) {} 
};

void attachGreater(Node* head) {
  std::stack <Node*> temp;
  temp.push(head);
  head = head->next;
  while(nullptr != head) {
    Node* tmp = nullptr;
    if(!temp.empty() && head->data > temp.top()->data)
      tmp = temp.top(), temp.pop();

    if(nullptr == tmp) {
      temp.push(head);
      head = head->next;
    } else {
      tmp->greater = head;
    }
  }
}

Node* constructList(std::vector<int>& list){
  Node* head = nullptr;
  Node* tmp = nullptr;
  Node* prev = nullptr;

  for(auto i : list) {
    tmp = new Node(i);
    if(nullptr == head) {
      head = tmp;
      prev = tmp;
    } else {
      prev->next = tmp;
      prev = tmp;
    }
  }
  return head;
}

void display(Node *head) {
  while(nullptr != head) {
    std::cout << "( " << head << " ) " << head->data << " -> " << head->greater << std::endl;
    head = head->next;
  }
}

int main () {
  std::vector<int> l = {5, 3, 1, 4, 9, 6};
  Node* head = constructList(l);
  attachGreater(head);
  display(head);
  return 0;
}
