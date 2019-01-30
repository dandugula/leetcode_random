class Solution {
public:
    void deleteNode(ListNode* node) {
      ListNode* temp = node->next;

      *node = *(node->next);
      delete temp;

      return;
    }
};
