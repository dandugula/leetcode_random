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
	ListNode * detectCycle(ListNode *head) {
		ListNode* slowPtr = head;
		ListNode* fastPtr = head;

		while (fastPtr && fastPtr->next) {
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;

			if (fastPtr == slowPtr) {
				fastPtr = head;

				while (fastPtr != slowPtr) {
					slowPtr = slowPtr->next;
					fastPtr = fastPtr->next;
				}

				return slowPtr;
			}

		}

		return nullptr;
	}
};