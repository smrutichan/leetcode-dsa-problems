/*
Problem: Coin Change

Approach:
- Use DP
- dp[i] = minimum coins needed to make amount i
- Initialize dp[0] = 0, others = INF
- For each amount:
    try all coins
    dp[i] = min(dp[i], dp[i - coin] + 1)

Time Complexity: O(n * amount)
Space Complexity: O(amount)
*/

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    // initialize
    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                int val = dp[i - coins[j]] + 1;
                if (val < dp[i]) dp[i] = val;
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
