/*
Problem: 9. Palindrome Number
Approach: Reverse Integer (Mathematical)

Time Complexity: O(d)
- where d is the number of digits in the number
Space Complexity: O(1)
*/

#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    int temp = x;
    long long reversed_num = 0;

    while (temp != 0) {
        reversed_num = reversed_num * 10 + (temp % 10);
        temp /= 10;
    }
    return x == reversed_num;
}
