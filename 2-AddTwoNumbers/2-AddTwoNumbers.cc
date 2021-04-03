/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit;
        ListNode* res = new ListNode(0);
        ListNode* hd = res;
        while(l1 || l2) {
        	if (l1 && l2) {
        		digit = res->val + l1->val + l2->val;
            }
        	else if (l1 && !l2) {
        		digit = res->val + l1->val;
            }
        	else if (!l1 && l2) {
        		digit = res->val + l2->val;
            }
        	if ((digit / 10) == 1) {
        		res->val = digit % 10;
                res->next = new ListNode(1);
        	} else {
        		res->val = digit;
        	}
            if (res->next == nullptr && (l1->next || l2->next)) {
                res->next = new ListNode(0);
            }
            // update l1,l2,res
            res = res->next;
            if (l1->next && l2->next) {
                l1 = l1->next;
                l2 = l2->next;
            }
        	else if (l1->next && !l2->next) {
        		l1 = l1->next;
                l2->next = new ListNode(0);
                l2 = l2->next;
        	} 

        	else if (l2->next && !l1->next) {
        		l2 = l2->next;
                l1->next = new ListNode(0);
                l1 = l1->next;
        	}
            else {
                l1 = nullptr;
                l2 = nullptr;
            }
        }
        return hd;
    }
};