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
            
