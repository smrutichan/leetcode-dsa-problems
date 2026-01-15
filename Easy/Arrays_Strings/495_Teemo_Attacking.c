/*
Problem: Teemo Attacking

Approach:
- Traverse the attack time array and for each attack, calculate the time gap to the next attack
- Add the minimum of the gap and the poison duration to the total
- Add the full duration for the last attack

Time Complexity: O(n)
Space Complexity: O(1)
*/

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeriesSize == 0)
        return 0;

    int total = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++) {
            int gap = timeSeries[i + 1] - timeSeries[i];
            total += (gap < duration) ? gap : duration;
    }
    // Add duration for the last attack
    total += duration;
    return total;
}
