"""
Problem: Group Anagrams

Approach:
- Use a hash map to group words
- Sort each word to create a unique key
- Words with the same sorted key are anagrams
- Store each word in the corresponding list
- Return all grouped anagrams

Time Complexity: O(n * k log k)
Space Complexity: O(n * k)
"""

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}

        for word in strs:
            key = "".join(sorted(word)) # key will be a sorted string of the word
            if key not in d:
                d[key] = []
            
            d[key].append(word) # value will be the word which is an anagram of the key
        return list(d.values())
