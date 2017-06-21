/*********************************
 *
 * Merge k sorted linked lists and return it as one sorted list. 
 * Analyze and describe its complexity.
 * 
 ********************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/***********************************/

class Solution {
public:
    struct cmp{
        bool operator() (ListNode* pn1, ListNode* pn2) {
            if (pn1 && pn2) {
                return pn1->val > pn2->val;
            } else {
                return false;
            }
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,  cmp> pq;

        for (auto& ln : lists) {
            if (ln) {
                pq.push(ln);
            }
        }

        if (pq.size() == 0) {
            return NULL;
        }

        ListNode* res = pq.top();
        pq.pop();
        ListNode* tail = res;
        ListNode* next = res->next;
        cout << tail -> val << endl;
        if (next) {
            pq.push(next);
        }

        while(!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            cout << tail -> val << endl;
            node = node->next;
            if (node) {
                pq.push(node);
            }
        }
        return res;
    }
};

/***********************************/
