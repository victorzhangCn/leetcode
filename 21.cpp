/***********************************
 * 
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 * 
 ***********************************/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/***********************************/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        if (l1 && l2) {
            if (l1->val < l2-> val) {
                head = tail = l1;
                l1 = l1->next;
            } else {
                head = tail = l2;
                l2 = l2->next;
            }

            while (l1 && l2) {
                if (l1 -> val < l2 -> val) {
                    tail->next = l1;
                    tail = tail->next;
                    l1 = l1->next;
                } else {
                    tail->next = l2;
                    tail = tail->next;
                    l2 = l2->next;
                }
            }
            
            if (l1) {
                tail->next = l1;
            } else {
                tail->next = l2;
            }

            return head;

        } else {
            return l2 == NULL ? l1 : l2;
        }
    }
};

/***********************************/

