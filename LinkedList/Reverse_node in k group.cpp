/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1){
            return head;
        }
        ListNode * dummy=new ListNode();
        dummy->next=head;
        ListNode* pre=dummy, *nex=dummy, *cur=dummy;
        int count=0;
        while(cur->next!=NULL){
            cur=cur->next;
            count++;
        }
        while(count>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=1; i<k; i++){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre=cur;
            count-=k;
        }
        return dummy->next;
        
    }
};
