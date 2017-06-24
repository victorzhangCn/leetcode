/*
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * 
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 */

#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pVector[k];

        ListNode* prev = newHead;
        ListNode* next = NULL;
        while(true) {
            if (prev->next) {
                pVector[0] = prev->next;
            } else {
                break;
            }

            bool needToReverse = true;
            for(int i = 1; i<k; ++i) {
                if (pVector[i-1]->next) {
                    pVector[i] = pVector[i-1]->next;
                } else {
                    needToReverse = false;
                    break;
                }
            }
            
            if (needToReverse) {
                next = pVector[k-1]->next;
            } else {
                break;
            }

            prev->next = pVector[k-1];
            for (int i = k-1; i > 0; --i) {
                pVector[i]->next = pVector[i-1];
            }
            pVector[0]->next = next;

            prev = pVector[0];
        }

        ListNode* res = newHead->next;
        delete newHead;
        return res;
    }
};

/******************************************/

int main() {
    Solution s;
    ListNode n0(0);
    ListNode n1(1);

    n0.next = &n1;
    n1.next = NULL;

    ListNode* res = s.reverseKGroup(&n0, 2);

    while(res) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}
