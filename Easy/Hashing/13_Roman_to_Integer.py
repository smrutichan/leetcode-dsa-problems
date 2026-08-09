'''
Problem: Roman to Integer

Approach:
- Use a dictionary to store key and value
- Compare current and next symbol values to handle subtraction cases

Time Complexity: O(n)
Space Complexity: O(1)
'''

class Solution:
    def romanToInt(self, s: str) -> int:
        d = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        result = 0

        for i in range(len(s)):
            if i + 1 < len(s) and d[s[i]] < d[s[i + 1]]:
                result -= d[s[i]]
            else:
                result += d[s[i]]

        return result
            

