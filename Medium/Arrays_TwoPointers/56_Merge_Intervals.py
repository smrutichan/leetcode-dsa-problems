"""
Problem: Merge Intervals

Approach:
- Sort intervals based on their start time
- Initialize the result with the first interval
- For each remaining interval:
    - If it overlaps with the last interval in the result, merge them
    - Otherwise, add it as a new interval
- Return the merged intervals

Time Complexity: O(n log n)
Space Complexity: O(n)
"""

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        result = [intervals[0]]

        for i in range(1,len(intervals)):
            if(result[-1][1] >= intervals[i][0]):
                result[-1][1] = max(result[-1][1],intervals[i][1])
            else:
                result.append(intervals[i])
        return result
