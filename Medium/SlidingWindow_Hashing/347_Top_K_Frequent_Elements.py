"""
Problem: Top K Frequent Elements

Approach:
- Count the frequency of each element using a hash map
- Sort the elements in descending order of frequency
- Select and return the first k keys from the sorted list

Time Complexity: O(n log n)
Space Complexity: O(n)
"""

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1

        topk = [key for key, value in sorted(d.items(), key=lambda x: x[1], reverse=True)[:k]]
        return topk
