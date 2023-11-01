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

    ListNode* reverse(ListNode* curr){
        ListNode *temp=NULL;
        while(curr!=NULL){
            ListNode *next=curr->next;
            curr->next=temp;
            temp=curr;
            curr=next;
        }
        return temp;
    }

    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        int carry=0;
        ListNode* ansLL=new ListNode();
        ListNode* temp=ansLL;
        while(head!=NULL || carry!=0){
            int sum=0;
            if(head!=NULL) sum=2*head->val;
            sum+=carry;
            int ans=sum%10;
            carry=sum/10;

            ListNode *curr=new ListNode(ans);
            temp->next=curr;
            temp=temp->next;

            if(head!=NULL) head=head->next;
        }
        return reverse(ansLL->next);
    }
};