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
    bool hasCycle(ListNode *head) {
        ListNode* sl=head;
        ListNode* ft=head;
        while(ft!=nullptr && ft->next!=nullptr){
            sl=sl->next;
            ft=ft->next->next;
            if(sl==ft){
                return true;
            }
        }
        return false;
    }
};