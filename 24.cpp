/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 * 
 */

#include <iostream>
using namespace std;

/*************************************************/

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*************************************************/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead;
        while(true) {
            if (pre->next == NULL) {
                break;
            }
            ListNode* p1 = pre->next;
            if (p1->next == NULL) {
                break;
            }
            ListNode* p2 = p1->next;
            ListNode* next = p2->next;

            pre->next = p2;
            p2->next = p1;
            p1->next = next;

            pre = p1;
        }

        ListNode* res = newHead->next;
        delete newHead;
        return res;
    }
};
