/*
Problem: Koko Eating Bananas

Approach:
- Use binary search on eating speed k
- For each k, compute total hours needed
    hours += ceil(piles[i] / k)
- If hours <= h → try smaller k
- Else → increase k

Time Complexity: O(n log max)
Space Complexity: O(1)
*/

#include <stdio.h>

int canEat(int* piles, int n, int k, int h) {
    long hours = 0;

    for (int i = 0; i < n; i++) {
        hours += (piles[i] + k - 1) / k;  
    }
    return hours <= h;
}

int minEatingSpeed(int* piles, int n, int h) {
    int left = 1, right = 0;

    // find max pile
    for (int i = 0; i < n; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canEat(piles, n, mid, h)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
