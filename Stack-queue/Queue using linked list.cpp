/*Implement a Queue using Linked List. 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)
Examples:
Input: Q = 5, Queries = [[1, 2], [1, 3], [2], [1, 4], [2]]
Output: 2 3 
Explanation: 
[1,2] queue will be 2
[1,3] queue will be 2,3
[2] poped element will be 2 the queue will be 3
[1, 4] queue will be 3, 4
[2] poped element will be 3 
Input: Q = 4, Queries = [[1, 2], [2], [2], [1, 3]]
Output: 2 -1
Explanation:
[1, 2] queue will be 2
[2]  poped element will be 2 then
    the queue will be empty. 
[2]  the queue is empty and hence -1
[1, 3] the queue will be 3*/




  /* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
     QueueNode *temp=new  QueueNode(x);
     if(front==NULL){
         front=rear=temp;
     }else{
         rear->next=temp;
         rear=temp;
     }
    
    
        
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL){
        return -1;
    }
    QueueNode *temp=front;
    front=front->next;
    int val=temp->data;
    delete temp;
    return val;
        // Your Code       
}
