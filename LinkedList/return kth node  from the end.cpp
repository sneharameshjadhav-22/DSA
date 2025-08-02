/*You are given the head of a linked list and the number k, You have to return the kth node from the end of linkedList. If k is more than the number of nodes, then the return -1.
Examples
Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.

Input: LinkedList: 10->5->100->5, k = 5
Output: -1
Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.
Constraints:
1 ≤ number of nodes ≤ 106
1 ≤ node->data , x ≤ 106
1 ≤ k ≤ 106*/


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
   
    int getKthFromLast(Node* head, int k) {
        if(head==nullptr) return -1;
        // code here
       int len=0;
       Node* temp=head;
       
       while(temp){
           len++;
           temp=temp->next;
       }
       if(k>len) return -1;
       temp=head;
       for(int i=0 ; i<len-k ; i++){
           temp=temp->next;
       }
       
       return temp->data;
    }
    
};
