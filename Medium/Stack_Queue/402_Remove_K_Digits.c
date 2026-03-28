/*
Problem: Remove K Digits

Approach:
- Use stack (array)
- Remove bigger previous digits when smaller digit comes
- Remove extra k from end
- Skip leading zeros
- Return result or "0"

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
    int n = strlen(num);
    char* stack = (char*)malloc(n + 1);
    int top = -1;

    // build stack
    for (int i = 0; i < n; i++) {
        while (top >= 0 && k > 0 && stack[top] > num[i]) {
            top--;
            k--;
        }
        stack[++top] = num[i];
    }

    // remove extra digits
    top -= k;

    // remove leading zeros
    int i = 0;
    while (i <= top && stack[i] == '0') i++;

    // if empty
    if (i > top) {
        char* res = (char*)malloc(2);
        strcpy(res, "0");
        return res;
    }

    // create result
    char* res = (char*)malloc(top - i + 2);
    int j = 0;
    while (i <= top) {
        res[j++] = stack[i++];
    }
    res[j] = '\0';
    return res;
}
