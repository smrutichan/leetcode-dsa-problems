/*
Problem: Crawler Log Folder

Approach:
- Use a stack to simulate folder navigation
- The final stack size gives the number of steps required to return to the main folder

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <string.h>

int minOperations(char** logs, int logsSize) {
    char* stack[logsSize];
    int top = -1;

    for (int i = 0; i < logsSize; i++) {
        if (strcmp(logs[i], "../") == 0) {
            if (top >= 0) { // Only if not already in main folder
                top--; 
            }
        } else if (strcmp(logs[i], "./") == 0) {
            // Stay in same folder → do nothing
        } else {
            top++;
            stack[top] = logs[i];
        }
    }
    // Number of steps to return to main folder
    return top + 1;
}
