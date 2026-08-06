"""
Problem: Longest Common Prefix

Approach:
- Assume the first string is the common prefix
- Compare it with each string
- While the current string does not start with the prefix, remove the last character from the prefix
- Return the remaining prefix

Time Complexity: O(n * m)
Space Complexity: O(1)

where:
n = number of strings
m = length of the shortest string
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]
    
        for word in strs:
            while not word.startswith(prefix):
                prefix = prefix[:-1]
        
        return prefix
