/**
 *  
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
 */

#include <cstdlib>
#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/***********************************************************/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* pTail = head;
        bool needAdd = false;
        while(p1 && p2) {
            int res = p1->val + p2->val;
            if (needAdd) {
                res += 1;
            }
            ListNode* newNode = new ListNode(res%10);
            if (!head) {
                head = newNode;
                pTail = newNode;
            } else {
                pTail->next = newNode;
                pTail = pTail->next;
            }
            needAdd = res >= 10 ? true:false;

            p1 = p1->next;
            p2 = p2->next;
        }

        ListNode* p = NULL;
        if(p1) {
            p = p1;
        }
        if(p2) {
            p = p2;
        }

        while(p) {
            int res = p->val;
            if (needAdd) {
                res += 1;
            }
            ListNode* newNode = new ListNode(res%10);
            if (!head) {
                head = newNode;
                pTail = newNode;
            } else {
                pTail->next = newNode;
                pTail = pTail->next;
            }
            needAdd = res >= 10 ? true:false;

            p = p->next;
        }

        if (needAdd) {
            ListNode* newNode = new ListNode(1);
            pTail->next = newNode;
            pTail = pTail -> next;
        }

        return head;
    }
};
/***********************************************************/

ListNode* construct(int* nums, size_t len) {
    ListNode* head = NULL;
    ListNode* tail = head;
    for (size_t i=0; i<len; i++) {
        ListNode* newNode = new ListNode(nums[i]);
        if(head) {
            tail->next = newNode;
            tail = tail->next;
        } else {
            head = newNode;
            tail = newNode;
        }
    }
    return head;
}

void deleteList(ListNode* head) {
    ListNode* p = head;
    head = NULL;
    while(p) {
        ListNode* tmp = p;
        p = p->next;
        free(tmp);
    }
}

void printList(ListNode* head) {
    ListNode* p = head;
    head = NULL;
    while(p) {
        cout << p->val << "->";
        p = p->next;
    }
    cout <<endl;
}


int main() {
    int num1[] = {5};
    int num2[] = {5};

    ListNode* lst1 = construct(num1, 1);
    ListNode* lst2 = construct(num2, 1);

    Solution s;
    ListNode* lstRes = s.addTwoNumbers(lst1, lst2);

    printList(lstRes);

    deleteList(lstRes);
    deleteList(lst1);
    deleteList(lst2);

}
