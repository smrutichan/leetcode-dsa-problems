/*
Problem: Cheapest Flights Within K Stops

Approach:
- Use Bellman-Ford (relax edges K+1 times)
- For each iteration:
    update costs using previous iteration values
- Only allow up to K stops

Time Complexity: O(K * E)
Space Complexity: O(n)
*/

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int cost[n];
    
    // initialize
    for (int i = 0; i < n; i++)
        cost[i] = INT_MAX;

    cost[src] = 0;
    for (int i = 0; i <= k; i++) {
        int temp[n];

        // copy manually
        for (int j = 0; j < n; j++)
            temp[j] = cost[j];

        // relax edges
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int price = flights[j][2];

            if (cost[u] != INT_MAX && cost[u] + price < temp[v]) {
                temp[v] = cost[u] + price;
            }
        }

        // update cost
        for (int j = 0; j < n; j++)
            cost[j] = temp[j];
    }
    return cost[dst] == INT_MAX ? -1 : cost[dst];
}
