/*Let's give it a try! You have a linked list and must implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 
The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.
Note: The input is given in the form of queries. Since there are two operations push() and pop(), there is two types of queries as described below:
(i) 1   (a query of this type takes x as another parameter and pushes it into the stack)
(ii) 2  (a query of this type means to pop an element from the stack and return the popped element)
Input is separated by space and as described above. 
Examples :
Input: [[1,2], [1,3], [2], [1,4], [2]]
Output: [3, 4]
Explanation: 
push(2)  : the stack will be {2}
push(3)  : the stack will be {2 3}
pop()    : poped element will be 3,the stack will be {2}
push(4)  : the stack will be {2 4}
pop()    : poped element will be 4
Input: [[2], [1,4], [1,5], [2]]
Output: [-1, 4]
Explanation: 
pop()    : the stack is empty so its -1.
push(4)  : the stack will be {4}
push(5)  : the stack will be {4 5}
pop()    : poped element will be 5, the stack will be {4}
Expected Time Complexity: O(1)
Expected Auxillary Space: O(1)*/

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* temp=new StackNode(x);
        temp->next=top;
        top=temp;
        
    }

    int pop() {
        
        // code here
        if(top==NULL){
            return -1;
        }
        StackNode* temp=top;
        top=top->next;
        int val=temp->data;
        delete temp ;
        return val;
        
        
    }

    MyStack() { top = NULL; }
};
