/*
Problem: Find Minimum in Rotated Sorted Array

Approach:
- Use binary search

Time Complexity: O(log n)
Space Complexity: O(1)
*/

#include <stdio.h>

int findMin(int* nums, int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}
