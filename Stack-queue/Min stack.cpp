/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/



class MinStack {
    stack<int>st;
    stack<int>minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(minst.empty() || val<=minst.top()){
            minst.push(val);
        }
        st.push(val);
        
    }
    
    void pop() {
        if(st.top() ==minst.top()){
            minst.pop();
        }
        st.pop();
        
    }
    
    int top() {
        
        return st.top();
        
    }
    
    int getMin() {
        return minst.top();
        
        
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 class Solution {
    stack<int>st;
    stack<int>min;
  public:
    Solution() {
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        if(min.empty() || x<=min.top()){
            min.push(x);
        }
        st.push(x);
        
        // code here
    }

    // Remove the top element from the Stack
        
    void pop() {
        // code here
        
       if(!st.empty()){
           int topv=st.top();
           st.pop();
           if(topv==min.top()){
               min.pop();
           }
           
       }
        
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st.empty()){
            return st.top();
        }else{
            return -1;
        }
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!min.empty()){
            return min.top();
        }else{
            return -1;
        }
    }
};
