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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode * fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode * cur= fakeHead, * nthpre = fakeHead;
        while(cur != NULL){
            cur = cur->next;
            count ++;
            if(count > n + 1) nthpre = nthpre->next;
        }
        ListNode * nth = nthpre->next;
        nthpre->next = nth->next;
        ListNode * result = fakeHead->next;
        delete nth;
        delete fakeHead;
        return result;
    }
};