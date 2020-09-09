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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * l1p = l1, * l2p = l2, * fakeHead = new ListNode(0);
        ListNode * cur = fakeHead;
        
        while(l1p != NULL && l2p != NULL){
            if(l1p->val < l2p->val){
                cur->next = l1p;
                l1p = l1p->next;
                cur = cur->next;
            }else{
                cur->next = l2p;
                l2p = l2p->next;
                cur = cur->next;
            }
        }
        if(l1p != NULL) cur->next = l1p;
        if(l2p != NULL) cur->next = l2p;
        
        ListNode * result = fakeHead->next;
        delete fakeHead;
        return result;        
    }
};