class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* curr = head;
      while(curr && curr->next != nullptr) {
        if(curr->val == val) {
          ListNode* temp = curr->next;
          *curr = *temp;
          delete temp;
        }
        curr = curr->next;
      }
      return head;
    }
};
