'''
Problem: Valid Palindrome

Approach:
- Traverse the string and retain only alphanumeric characters while converting them to lowercase
- Use 2 pointers to check if all characters are same from left and right sides

Time Complexity: O(n)
Space Complexity: O(1)
'''

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(char.lower() for char in s if char.isalnum())
        
        left = 0
        right = len(s) - 1
        for i in range(len(s)//2):
            if s[left] != s[right]:
                return False
                
            left+=1
            right-=1
        
        return True
