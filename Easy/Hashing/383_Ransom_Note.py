'''
Problem: Ransom Note

Approach:
- Use a hash map to count the frequency of each character in the magazine
- For each character in the ransom note, reduce its count from the map
- If any character is unavailable, return false

Time Complexity: O(n)
Space Complexity: O(1)
'''

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        d = {}
        for i in magazine:
            d[i] = d.get(i,0)+1
        
        for i in ransomNote:
            if i not in d:
                return False
            
            if d[i] == 0: # To handle cases where there are repeating chars
                return False

            d[i] -= 1

        return True
