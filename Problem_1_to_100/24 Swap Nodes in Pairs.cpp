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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p1 = head, *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode * cur = fakeHead;
        
        while(p1!=NULL){
            ListNode *p2 = p1->next;
            if(p2 == NULL) {
                cur->next = p1;
                break;
            }
            ListNode * tmp = p2->next;
            cur->next = p2;
            p2->next = p1;
            p1->next = tmp;
            cur = p1;
            p1 = tmp;
        }
        
        ListNode * result = fakeHead->next;
        delete fakeHead;
        return result;
    }
};