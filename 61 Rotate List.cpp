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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        
        int cnt = 0;
        ListNode *end = nullptr;
        for(ListNode *iter = head; iter != nullptr; iter = iter->next){
            cnt ++;
            end = iter;
        }
        end->next = head;
        const int steps = cnt - k%cnt;
        
        for(int i = 0; i < steps - 1; i++){
            head = head->next;
        }
        
        auto result = head->next;
        head->next = nullptr;
        

        return result;
    }
};