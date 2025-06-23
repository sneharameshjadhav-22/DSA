/*Given the head of a linked list, rotate the list to the right by k places.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        temp->next= head;
        k= k%len;
        int newk=len-k;
        for(int i=1; i<=newk; i++){
            temp=temp->next;
        }
        
        head=temp->next;
        temp->next=NULL;
        return head;


        
    }
};
