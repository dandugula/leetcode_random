class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(nullptr == l1) return l2;
      if(nullptr == l2) return l1;
      ListNode* result = nullptr;
      if(l1->val <= l2->val) {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
      } else {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
      }
      return result;
    } 
};
