"""
Problem: Longest Repeating Character Replacement

Approach:
- Use a sliding window with a hash map to count character frequencies
- Expand the window by moving the right pointer
- If replacements needed exceed k, shrink the window from the left
- Track the maximum valid window length

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if not s:
            return 0
        
        d={}
        left = 0
        maxi = 0
        for right in range(len(s)):
            d[s[right]] = d.get(s[right],0) + 1

            while((right-left+1) - max(d.values()) > k):
                d[s[left]] -= 1 #Move the pointer forward

                if d[s[left]] == 0: #Save space in the dict
                    del d[s[left]]

                left+=1
                
            maxi = max(maxi,right-left+1)

        return maxi
