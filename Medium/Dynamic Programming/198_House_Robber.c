/*
Problem: House Robber

Approach:
- Use DP
- At each house, choose:
    rob → nums[i] + dp[i-2]
    skip → dp[i-1]

Time Complexity: O(n)
Space Complexity: O(1)
*/

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];

    int prev2 = 0;        // dp[i-2]
    int prev1 = nums[0];  // dp[i-1]

    for (int i = 1; i < numsSize; i++) {
        int take = nums[i] + prev2;
        int skip = prev1;

        int curr = (take > skip) ? take : skip;

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
