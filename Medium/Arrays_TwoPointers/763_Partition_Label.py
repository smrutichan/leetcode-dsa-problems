"""
Problem: Partition Labels

Approach:
- Store the last occurrence of each character
- Traverse the string and update the current partition's end
- When the current index reaches the partition end, record its size
- Start a new partition from the next index

Time Complexity: O(n)
Space Complexity: O(1)
"""

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        last = {}

        # Store the last occurrence of each character
        for i in range(len(s)):
            last[s[i]] = i

        start = 0
        end = 0
        ans = []

        for i in range(len(s)):
            end = max(end, last[s[i]])

            if i == end:
                ans.append(end - start + 1)
                start = i + 1

        return ans
            
