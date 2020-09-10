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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> lps;
        if(lists.size() == 0) return {};
        for(auto i = lists.begin(); i < lists.end(); i++){
            lps.push_back(*i);
        }
        
        auto compare = [](ListNode *i, ListNode *j){return (i==NULL ? INT_MAX:i->val) <(j==NULL ? INT_MAX:j->val); };
        sort(lps.begin(), lps.end(), compare);
        
        ListNode * fakeHead = new ListNode(0);
        ListNode * cur = fakeHead;
        
        while(lps[0] != NULL){
            cur->next=lps[0];
            cur = cur->next;
            lps.insert(upper_bound(lps.begin(), lps.end(), lps[0]->next, compare), lps[0]->next);
            lps.erase(lps.begin());
        }
        ListNode *result = fakeHead->next;
        delete fakeHead;
        return result;
    }
};