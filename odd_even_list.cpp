/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <algorithm>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *oddHead, *oddPrev, *oddTail, *evenHead, *evenPrev, *evenTail;
        oddHead = oddPrev = oddTail = evenHead = evenPrev = evenTail = nullptr;

        oddHead = head;
        oddTail = head;
        oddPrev = head;

        if(nullptr != head) {
            evenHead = head->next;
            evenPrev = head->next;
            evenTail = head->next;
        }

        while(evenTail != nullptr && oddPrev != nullptr) {
            oddTail = evenTail->next;
            oddPrev->next = oddTail;
            oddPrev = oddPrev->next;
            if(oddTail) {
                evenTail = oddTail->next;
                evenPrev->next = evenTail;
                evenPrev = evenPrev->next;
            }
        }
        
        while(oddHead && oddHead->next != nullptr)
            oddHead = oddHead->next;
        if(oddHead) oddHead->next = evenHead;

        return head;

    }
};

ListNode* populate_list(std::vector<int>& n) {
    ListNode* head = new ListNode(n[0]);
    ListNode* t = head;

    for(int i = 1; i < n.size(); ++i) {
        t->next = new ListNode(n[i]);
        t = t->next;
    }

    return head;
}

int main () {
    ListNode* l;
    Solution s;
    std::vector<int> nums = {2, 1, 3, 4};
    l = populate_list(nums);
    l = s.oddEvenList(l);
    while(l) {
        std::cout << l->val << " ";
        ListNode* t = l;
        l = l->next;
        delete t;
    }
    std::cout << std::endl;
}
