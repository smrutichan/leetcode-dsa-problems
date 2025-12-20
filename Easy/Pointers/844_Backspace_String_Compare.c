/*
Problem: Backspace String Compare

Approach:
- Two-pointer technique with backward traversal
- Skip characters affected by backspaces using counters

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool backspaceCompare(char* s, char* t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0) {
        // Find next valid character in s
        while (i >= 0) {
            if (s[i] == '#') {
                skipS++;
                i--;
            } else if (skipS > 0) {
                skipS--;
                i--;
            } else {
                break;
            }
        }
        // Find next valid character in t
        while (j >= 0) {
            if (t[j] == '#') {
                skipT++;
                j--;
            } else if (skipT > 0) {
                skipT--;
                j--;
            } else {
                break;
            }
        }

        // Compare characters
        if (i >= 0 && j >= 0) {
            if (s[i] != t[j]) return false;
        } else {
            // One string finished earlier
            if (i >= 0 || j >= 0) return false;
        }
        i--;
        j--;
    }
    return true;
}
