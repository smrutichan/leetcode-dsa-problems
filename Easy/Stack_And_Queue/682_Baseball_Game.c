/*
Problem: Baseball Game

Approach:
- Use a stack to maintain a record of valid scores
- Sum all values remaining in the stack to get the final score

Time Complexity: O(n)
Space Complexity: O(n)
*/

int calPoints(char** operations, int operationsSize) {
    int stack[operationsSize];
    int top = -1;

    for(int i = 0; i < operationsSize; i++){
        if(strcmp(operations[i],"C") == 0){
            top = top - 1; // Pop from stack
        }
        else if(strcmp(operations[i],"+") == 0){
            top++;
            stack[top] = stack[top - 1] + stack[top - 2];
        }
        else if(strcmp(operations[i],"D") == 0){
            top++;
            stack[top] = 2 * stack[top - 1];
        }
        else {
            top++;
            stack[top] = atoi(operations[i]); // Convert string to integer before pushing into stack
        }
    }

    int sum = 0;
    for(int i = 0; i <= top; i++){
        sum += stack[i];
    }
    return sum;
}
