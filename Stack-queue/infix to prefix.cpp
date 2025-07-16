/*Given an infix expression consisting of operators (+, -, *, /, ^) and operands (lowercase characters), the task is to convert it to a prefix expression.
Infix Expression: The expression of type a 'operator' b (a+b, where + is an operator) i.e., when the operator is between two operands.
Prefix Expression: The expression of type 'operator' a b (+ab where + is an operator) i.e., when the operator is placed before the operands.
Examples: 
Input: a*b+c/d
Output: +*ab/cd 
Input: (a-b/c)*(a/k-l)
Output: *-a/bc-/akl*/


int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPrefix(string infix) {
    // Step 1: Reverse the infix
    reverse(infix.begin(), infix.end());

    // Step 2: Swap brackets
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    stack<char> st;
    string result;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Operand
        if (isalnum(c)) {
            result += c;
        }
        // Left Parenthesis
        else if (c == '(') {
            st.push(c);
        }
        // Right Parenthesis
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // pop '('
        }
        // Operator
        else {
            while (!st.empty() && precedence(c) < precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Step 4: Reverse result
    reverse(result.begin(), result.end());
    return result;
}
