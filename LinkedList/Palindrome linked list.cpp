/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:
Input: head = [1,2]
Output: false*/



class Solution {
public:
    

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       
        ListNode* second=reverse(slow);
        ListNode* first=head;
        
        while(second!=NULL){
            if(second->val!=first->val){
                return false;
                
            }
            first=first->next;
            second=second->next;
            
        }
        return true;
        
    }

    ListNode* reverse(ListNode* head){
        ListNode *temp=NULL;
        while(head!=NULL){
            ListNode* next=head->next;
            head->next=temp;
            temp=head;
            head=next;
        }
        return temp;

    }
     
};
