/*
Problem: Reverse String

Approach:
- Use two pointers starting from both ends of the string
- Swap characters while moving the pointers inward

Time Complexity: O(n)
Space Complexity: O(1)
*/

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;

    while (left < right) {
        //Swapping the left-most and right-most elements iteratively
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
