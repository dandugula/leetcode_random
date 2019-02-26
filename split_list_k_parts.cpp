/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  inline int len(ListNode* root) {
    int l = 0;
    while(root) {
      ++l;
      root = root->next;
    }
    return l;
  }
  inline ListNode* split(ListNode* tail) {
    ListNode* t;
    if(tail) {
      t = tail->next;
      tail->next = nullptr;
    }
    return t;
  }
public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    std::vector<ListNode*> ret(k, nullptr);
    int listSize = len(root);
    int partSize = listSize / k; 
    int remElements = listSize % k;
    int current = 0;
    while(root) {
      int p = partSize - 1;
      ret[current++] = root;

      while(p-- > 0) 
        root = root->next;

      if(partSize && remElements) {
        root = root->next;
        remElements--;
      }
      root = split(root);
    }
    return ret;
  }
};
