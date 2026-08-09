"""
Problem: String to Integer (atoi)

Approach:
- Remove leading whitespace
- Handle optional sign (+ or -)
- Convert consecutive digits into an integer
- Stop when a non-digit is encountered
- Clamp the result within the 32-bit signed integer range

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()

        if not s:
            return 0

        sign = 1
        i = 0

        if s[0] == '-':
            sign = -1
            i = 1
        elif s[0] == '+':
            i = 1

        num = 0
        while i < len(s) and s[i].isdigit():
            num = num * 10 + int(s[i])
            i += 1

        num *= sign

        # Handling overflow
        if num > 2**31 - 1:
            return 2**31 - 1

        if num < -2**31:
            return -2**31

        return num
