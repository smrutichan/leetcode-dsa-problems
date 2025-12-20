/*
Problem: Is Subsequence

Approach:
- Two-pointer technique on strings
- Traverse the larger string while tracking matched characters in the smaller string

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool isSubsequence(char* s, char* t) {
    int i, j = 0;
    int lenS = strlen(s);

    for (i = 0; i < strlen(t); i++) {
        if (j < lenS && t[i] == s[j]) {
            j++;
        }
    }
    return j == lenS; // check if subsequence
}
