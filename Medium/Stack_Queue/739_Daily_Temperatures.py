'''
Problem: Daily Temperatures

Approach:
- Use a monotonic decreasing stack (store indices)
- While current temperature > stack top → resolve previous days
- Pop and calculate days waited

Time Complexity: O(n)
Space Complexity: O(n)
'''

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0]*len(temperatures)
        stack = []

        for i in range(len(temperatures)):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                prev = stack.pop()
                answer[prev] = i - prev

            stack.append(i)

        return answer
