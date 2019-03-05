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
	inline int len(ListNode* n) {
		int l = 0;
		while (n) {
			n = n->next;
			++l;
		}
		return l;
	}
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		int l = len(head);
		int idx = l - n;
		ListNode* prev = nullptr;
		ListNode* curr = head;

		for (int i = 0; i < idx; ++i) {
			prev = curr;
			curr = curr->next;
		}

		if (nullptr != prev)
			prev->next = curr->next;
		else
			head = head->next;

		delete curr;
		return head;
	}
};