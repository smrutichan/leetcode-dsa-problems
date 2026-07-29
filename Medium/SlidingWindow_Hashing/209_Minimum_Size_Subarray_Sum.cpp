/*
Problem: Minimum Size Subarray Sum

Approach:
- Use sliding window with two pointers
- Expand the right pointer and add elements to the current sum
- While the sum is at least the target:
    update the minimum length
    shrink the window from the left
- If no valid subarray exists, return 0

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int currSum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while (currSum >= target) {
                minLen = min(minLen, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }

        if (minLen == INT_MAX)
            return 0;

        return minLen;
    }
};
