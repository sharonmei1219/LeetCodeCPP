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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode * fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode * cur = fakeHead;
        while(cur->next != NULL){
            if(!longerThan(cur, k)) break;
            ListNode * curNext = cur->next;
            ListNode * remainder = reverseKNodesAndReturnRemainder(cur, k);
            curNext->next = remainder;
            cur=curNext;
        }
        ListNode * result = fakeHead->next;
        delete fakeHead;
        return result;
        
    }
    
    bool longerThan(ListNode* fakeHead, int k){
        ListNode * cur = fakeHead;
        for(int i = 0; i < k; i++){
            cur=cur->next;
            if(cur == NULL) return false;
        }
        return true;
    }
    ListNode* reverseKNodesAndReturnRemainder(ListNode* fakeHead, int k){
        ListNode *remainder = fakeHead->next;
        for(int i = 0; i < k; i++){
            if(remainder == NULL) break;
            ListNode *scdNodeInRemainder = remainder->next;
            remainder->next=fakeHead->next;
            fakeHead->next = remainder;
            remainder = scdNodeInRemainder;
        }
        return remainder;
    }
};