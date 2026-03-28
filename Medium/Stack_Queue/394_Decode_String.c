/*
Problem: Decode String

Approach:
- Use two stacks:
    1. count stack → stores repeat counts
    2. string stack → stores previous strings
- Traverse string:
    - If digit → build number
    - If '[' → push count and current string, reset current
    - If ']' → pop count and previous string, repeat current and append
    - Else → add character to current string

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Note: The returned string must be malloced, assume caller calls free().
 */
char* decodeString(char* s) {
    int n = strlen(s);

    // stacks
    int countStack[1000];
    char* stringStack[1000];
    int stringTop = -1;
    int countTop = -1;

    char* curr = (char*)calloc(1000, sizeof(char));
    int k = 0;

    for (int i = 0; i < n; i++) {

        if (isdigit(s[i])) {
            k = k * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            countStack[++countTop] = k;
            stringStack[++stringTop] = strdup(curr);

            k = 0;
            curr[0] = '\0';
        }
        else if (s[i] == ']') {
            int repeat = countStack[countTop--];
            char* prev = stringStack[stringTop--];
            char* temp = (char*)calloc(1000, sizeof(char));
            strcpy(temp, prev);

            for (int j = 0; j < repeat; j++) {
                strcat(temp, curr);
            }

            strcpy(curr, temp);
            free(temp);
            free(prev);
        }
        else {
            int len = strlen(curr);
            curr[len] = s[i];
            curr[len + 1] = '\0';
        }
    }
    return curr;
}
