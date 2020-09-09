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
    ListNode* partition(ListNode* head, int x) {
        ListNode fakeHead(0, head), fakeBigHead(0, nullptr);
        ListNode * cur = head, * preCur = &fakeHead;
        ListNode * bigTail = &fakeBigHead;
        while(cur !=nullptr){
            if(cur->val < x){
                preCur = cur;
                cur = cur->next;
            }else{
                ListNode * temp = cur;
                preCur->next = cur->next;
                cur = cur->next;
                temp->next=nullptr;
                bigTail->next = temp;
                bigTail = temp;
            }
        }
        preCur->next = fakeBigHead.next;
        return fakeHead.next;
        
    }
};