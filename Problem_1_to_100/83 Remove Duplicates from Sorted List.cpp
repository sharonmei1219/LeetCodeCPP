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
        ListNode * result = head, * cur = head->next, * tail = head;
        while(cur != nullptr){
            if(cur->val == tail->val){
                ListNode * dup = cur;
                cur = cur->next;
                tail->next =cur;
                delete dup;
            }else{
                tail = cur;
                cur = cur->next;
            }
        }
        return result;       
    }
};