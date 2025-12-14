/*
Problem: Plus One

Approach:
- Traverse the digit array from right to left, handling carry by incrementing digits and setting 9s to 0
- If all digits are 9, allocate a new array with an extra digit and set the leading digit to 1 and rest to 0

Why malloc is used:
- Ensures the returned array remains valid after function completes execution

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Start from last digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    
    // If all digits were 9 (e.g., 999 → 1000)
    int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));
    result[0] = 1;
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }
    *returnSize = digitsSize + 1;
    return result;
}
