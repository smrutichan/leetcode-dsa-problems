"""
Problem: Reverse Words in a String III

Approach:
- Split the string into individual words
- Reverse each word separately
- Join the reversed words with spaces
- Return the modified string

Time Complexity: O(n)
Space Complexity: O(n)
"""

class Solution:
    def reverseWords(self, s: str) -> str:
        L = s.split(" ")

        for i in range(len(L)):
            L[i] = L[i][::-1]

        return " ".join(L)
