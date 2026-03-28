/*
Problem: Climbing Stairs II

Approach:
- Use DP where dp[i] = minimum cost to reach step i
- From each step, we can jump +1, +2, +3
- Transition:
    dp[i] = min(
        dp[i-1] + cost[i] + (1-1)^2,
        dp[i-2] + cost[i] + (2-1)^2,
        dp[i-3] + cost[i] + (3-1)^2
    )
- Return dp[n]

Time Complexity: O(n)
Space Complexity: O(n)
*/

int climbStairs(int n, int* costs, int costsSize) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;

        // 1 step
        if (i >= 1) {
            int val = dp[i-1] + costs[i-1] + 1;
            if (val < dp[i]) dp[i] = val;
        }

        // 2 steps
        if (i >= 2) {
            int val = dp[i-2] + costs[i-1] + 4;
            if (val < dp[i]) dp[i] = val;
        }

        // 3 steps
        if (i >= 3) {
            int val = dp[i-3] + costs[i-1] + 9;
            if (val < dp[i]) dp[i] = val;
        }
    }
    return dp[n];
}
