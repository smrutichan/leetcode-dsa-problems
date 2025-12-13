/*
Problem: 58. Length of Last Word
Approach:
- Backward scan to skip trailing spaces and count characters of the last word

Time Complexity: O(n)
Space Complexity: O(1)
*/

int lengthOfLastWord(char* s) {
    int length = strlen(s);
    int count = 0;
    int i = length - 1;

    //skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    //length of last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    return count;
}
