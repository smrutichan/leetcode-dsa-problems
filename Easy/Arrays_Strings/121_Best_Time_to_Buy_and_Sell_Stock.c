/*
Problem: Best Time to Buy and Sell Stock

Approach:
- Single pass traversal using an array
- Track the minimum buying price so far
- Update maximum profit when a better selling price is found

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2)
        return 0;

    int buy = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        //update buy if we find a cheaper price
        if (prices[i] < buy) {
            buy = prices[i];
        }
        //try selling on day i
        else if (prices[i] - buy > maxProfit) {
            maxProfit = prices[i] - buy;
        }
    }
    return maxProfit;
}
