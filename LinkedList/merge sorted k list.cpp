/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.
Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:
Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.*/





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
    ListNode* merge(ListNode* head1, ListNode*head2){
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(head1!=NULL && head2!=NULL){
            if(head1->val <=head2->val){
                curr->next=head1;
                head1=head1->next;
            }else{
                curr->next=head2;
                head2=head2->next;

            }
            curr=curr->next;
        }
        if(head1!=NULL){
            curr->next=head1;
        }else{
            curr->next=head2;
        }
        return dummy->next;


    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          ListNode* res=NULL;
          for( ListNode* node : lists){
            res=merge(res, node);


          }
          return res;

        


        
    }
};
