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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* p1 = l1, * p2 = l2, * res = new ListNode(0), * resTail = res;
    	int carryBit = 0;
    	while (p1 != NULL || p2 != NULL){
			resTail->next = new ListNode((add(p1, p2)+carryBit)%10);
    		resTail = resTail->next;
    		carryBit = (add(p1, p2) + carryBit)/10;
    		p1 = next(p1);
    		p2 = next(p2);
    	}
    	if(carryBit == 1) {resTail->next= new ListNode(1);}

    	ListNode * tmp = res;
    	res = res->next;
    	delete tmp;
        return res;
        
    }
private:
	int add(ListNode* p1, ListNode* p2){
		int val1 = p1==NULL?0:p1->val;
		int val2 = p2==NULL?0:p2->val;
		return val1 + val2;
	}

	ListNode* next(ListNode* p){
		return p==NULL?NULL:p->next;
	}
};