/*
Problem: Gas Station

Approach:
- Traverse all gas stations while tracking current fuel balance and maintain a total fuel balance as well
- If current fuel becomes negative at any station, reset the starting index to the next station
- If total fuel balance is non-negative, the last recorded start index is the solution

Time Complexity: O(n)
Space Complexity: O(1)
*/

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    if (gasSize != costSize) {
        return -1;
    }

    int tank = 0;
    int total = 0; // total gas balance for entire cycle
    int start = 0; // starting gas station's index

    for (int i = 0; i < gasSize; i++) {
        int diff = gas[i] - cost[i];
        tank += diff;
        total += diff;

        if (tank < 0) { // gas[i] < cost[i] so car cannot start from this index
            start = i + 1;
            tank = 0;
        }
    }
    if (total >= 0)
        return start;
    else
        return -1;
}
