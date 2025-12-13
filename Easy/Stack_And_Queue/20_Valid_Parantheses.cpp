/*
Problem: Valid Parentheses

Approach:
- Stack-based validation using a character array
- Push opening brackets and match them with closing brackets

Time Complexity: O(n)
Space Complexity: O(n)
*/

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for(int i = 0; i < len; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[++top] = s[i]; // Push the open brackets into the stack
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if(top == -1) return false; // If stack is empty then there will be unmatched brackets so invalid

            char topChar = stack[top--]; // Pop the topmost element in the stack
            if ((s[i] == ')' && topChar != '(') || (s[i] == '}' && topChar != '{') || (s[i] == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return top == -1; // Stack should be empty if all brackets are valid/matched
}
