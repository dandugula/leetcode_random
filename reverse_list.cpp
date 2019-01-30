class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* cur = head;
      ListNode* prev = nullptr;
      
      while(cur) {
        ListNode* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
      }
      
      return prev;
    }
};
