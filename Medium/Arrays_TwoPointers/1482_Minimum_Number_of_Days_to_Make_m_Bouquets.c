/*
Problem: Minimum Number of Days to Make m Bouquets

Approach:
- Use binary search on days

Time Complexity: O(n log maxDay)
Space Complexity: O(1)
*/

int minDays(int* bloomDay, int bloomDaySize, int m, int k) {
    if ((long)m * k > bloomDaySize) return -1;
    int left = INT_MAX, right = 0;

    // find min and max
    for (int i = 0; i < bloomDaySize; i++) {
        if (bloomDay[i] < left) left = bloomDay[i];
        if (bloomDay[i] > right) right = bloomDay[i];
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        int bouquets = 0, count = 0;

        // check if possible
        for (int i = 0; i < bloomDaySize; i++) {
            if (bloomDay[i] <= mid) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        if (bouquets >= m)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}
