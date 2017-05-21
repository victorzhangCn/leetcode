/***************************************************
 * 
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 *    Given linked list: 1->2->3->4->5, and n = 2.
 * 
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 **************************************************/

/**
 * Definition for singly-linked list.
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**************************************************/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> pointers;
        ListNode* p = head;
        while(p) {
            pointers.push_back(p);
            p = p->next;
        };

        size_t index = pointers.size() - n;
        ListNode* p_to_delete = pointers[index];
        if (p_to_delete == head) {
            ListNode* tmp = head->next;
            delete head;
            return tmp;
        } else {
            ListNode* p_prev = pointers[index-1];
            p_prev->next = p_to_delete->next;
            delete p_to_delete;
            return head;
        }
    }
};

/**************************************************/
