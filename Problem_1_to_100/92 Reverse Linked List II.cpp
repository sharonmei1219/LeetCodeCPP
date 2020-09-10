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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode fakeHead(0, head);
        ListNode * cur = head, * m_1 = &fakeHead, * preCur = &fakeHead;
        int nodeCnt = 1;
        for(int i = 0; i < m; i++){
            m_1 = preCur;
            preCur = cur;
            cur = cur->next;
        }
        
        for(int i = m; i < n; i++ ){
            preCur->next = cur->next;
            cur->next = m_1->next;
            m_1->next = cur;
            cur = preCur->next;
        }
        return fakeHead.next;
    }

};