/*
Problem: Valid Palindrome

Approach:
- Traverse the string and retain only alphanumeric characters while converting them to lowercase

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int i = 0, j = 0;
    // Remove non alpha-numeric chars
    while (s[i]) {
        if (isalnum(s[i])) {
            s[j++] = tolower(s[i]); // Convert to lowercase
        }
        i++;
    }
    s[j] = '\0';   // Terminate the string

    int length = j;
    // Check palindrome
    for (i = 0; i < length / 2; i++) {
        if (s[i] != s[length - i - 1]) {
            return false;
        }
    }
    return true;
}
