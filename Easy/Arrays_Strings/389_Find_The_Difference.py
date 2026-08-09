"""
Problem: Find the Difference

Approach:
- Use a hash map to count characters in s
- Traverse t and decrease the corresponding frequency
- If a character is missing or its count reaches 0, it is the extra character
- Return the extra character

Time Complexity: O(n)
Space Complexity: O(n)
"""

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        d = {}
        for i in s:
            d[i] = d.get(i,0)+1
        
        for i in t:
            if i not in d:
                return i
            
            if d[i] == 0: # To handle cases where there are repeating chars
                return i

            d[i] -= 1
