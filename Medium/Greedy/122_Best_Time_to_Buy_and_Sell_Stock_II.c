/*
Problem: Best Time to Buy and Sell Stock II

Approach:
- Traverse the price array day by day
- For every day where the price increases compared to the previous day, add the difference to profit

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;

    for (int i = 0; i < pricesSize - 1; i++) {
        if (prices[i + 1] > prices[i]) {
            profit += prices[i + 1] - prices[i];
        }
    }
    return profit;
}
