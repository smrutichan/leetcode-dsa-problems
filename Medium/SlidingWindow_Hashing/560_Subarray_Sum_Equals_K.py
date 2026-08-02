"""
Problem: Subarray Sum Equals K

Approach:
- Use prefix sum and a hash map
- Store the frequency of each prefix sum
- For each element, check if (current prefix sum - k) exists in the map
- If it exists, add its frequency to the answer
- Update the current prefix sum frequency in the map

Time Complexity: O(n)
Space Complexity: O(n)
"""

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        count = 0
        d = {0: 1}

        for num in nums:
            prefixSum += num

            if prefixSum - k in d:
                count += d[prefixSum - k]

            d[prefixSum] = d.get(prefixSum, 0) + 1

        return count
