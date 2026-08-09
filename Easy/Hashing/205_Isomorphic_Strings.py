'''
Problem: Isomorphic Strings

Approach:
- Hashing using two unordered maps
- Maintain bidirectional character mapping between both strings

Time Complexity: O(n)
Space Complexity: O(n)
'''

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        s_to_t = {}
        t_to_s = {}

        for i in range(len(s)):
            c1 = s[i]
            c2 = t[i]

            if c1 in s_to_t:
                if s_to_t[c1] != c2:
                    return False
            else:
                s_to_t[c1] = c2

            if c2 in t_to_s:
                if t_to_s[c2] != c1:
                    return False
            else:
                t_to_s[c2] = c1

        return True
