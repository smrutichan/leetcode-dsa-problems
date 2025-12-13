/*
Problem: 14. Longest Common Prefix
Approach:
- String manipulation using character arrays

Time Complexity: O(n * m)
- n is the number of strings
- m is the length of the prefix
Space Complexity: O(1)
*/

#include <string.h>
#include <stddef.h> // For size_t

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    
    char *LCP = strs[0];
    for (int i = 1; i < strsSize; i++) {
        char *current_str = strs[i];
        
        while (strncmp(current_str, LCP, strlen(LCP)) != 0) {
            size_t current_len = strlen(LCP);
            if (current_len == 0) {
                return "";
            }
            LCP[current_len - 1] = '\0';
        }
    }
    return LCP;
}
