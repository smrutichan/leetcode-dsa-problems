/*
Problem: Min Cost Climbing Stairs

Approach:
- Dynamic programming used to track min cost to reach the previous two steps

Time Complexity: O(n)
Space Complexity: O(1)
*/

int minCostClimbingStairs(int* cost, int costSize) {
    int prev2 = 0;  // min cost to reach step (i-2)
    int prev1 = 0;  // min cost to reach step (i-1)

    for (int i = 0; i < costSize; i++) {
        // Min cost to reach current step
        int curr = cost[i] + (prev1 < prev2 ? prev1 : prev2);
        // Shift the window
        prev2 = prev1;
        prev1 = curr;
    }
    // Top can be reached from last or second-last step
    return (prev1 < prev2) ? prev1 : prev2;
}
