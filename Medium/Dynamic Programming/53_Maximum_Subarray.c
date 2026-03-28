/*
Problem: Maximum Subarray

Approach:
- Use DP
- Keep current sum
- If sum becomes negative → reset to 0
- Track maximum sum seen so far

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxSubArray(int* nums, int n) {
    int maxSum = nums[0];
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += nums[i];

        if (currSum > maxSum)
            maxSum = currSum;

        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}
