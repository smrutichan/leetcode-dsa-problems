/*
Problem: Capacity To Ship Packages Within D Days

Approach:
- Use binary search on capacity
- Range:
    left = max(weights) (minimum possible capacity)
    right = sum(weights) (maximum possible capacity)
- For each capacity:
    count days required
- If days <= D → try smaller capacity
- Else → increase capacity
- Return minimum valid capacity

Time Complexity: O(n log sum)
Space Complexity: O(1)
*/

#include <stdio.h>

int canShip(int* weights, int n, int capacity, int days) {
    int d = 1;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        if (curr + weights[i] > capacity) {
            d++;
            curr = 0;
        }
        curr += weights[i];
    }
    return d <= days;
}

int shipWithinDays(int* weights, int n, int days) {
    int left = 0, right = 0;

    // find bounds
    for (int i = 0; i < n; i++) {
        if (weights[i] > left)
            left = weights[i];
        right += weights[i];
    }

    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canShip(weights, n, mid, days)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
