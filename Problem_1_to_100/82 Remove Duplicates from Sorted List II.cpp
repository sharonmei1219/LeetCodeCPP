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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode * cur = head->next;
        ListNode  * tailPre = new ListNode(head->val - 1, head);
        ListNode * resultPre = tailPre;
        int dup = head->val;
        while(cur != nullptr){
            if(cur->val != dup){
                if(cur == tailPre->next && cur != nullptr) {
                    dup = cur->val;
                    cur = cur->next;
                }else{
                    tailPre = tailPre->next;
                    dup = cur->val;
                    cur = cur->next;
                }
                continue;
            }
            if(cur->val == dup){
                if(cur != tailPre->next){
                    ListNode * temp = tailPre->next;
                    tailPre->next = temp->next;
                    delete(temp);
                }
                ListNode * temp = cur;
                cur = temp->next;
                tailPre->next = cur;
                delete(temp);
            }
        }
        return resultPre->next;

    }
};