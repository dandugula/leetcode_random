/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* first = head;
      ListNode* curr = head;
      while(first) {
        curr = first->next;
        while(curr && curr->val == first->val) {
          ListNode* tmp = curr;
          curr = curr->next;
          delete tmp;
        }
        first->next = curr;
        first = curr;
      }      
      return head;
    }
};
