/*
Problem: Search Insert Position

Approach:
- Binary search on a sorted array

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int searchInsert(int* nums, int numsSize, int target) {
    int lb = 0, ub = numsSize - 1;

    while (lb <= ub) {
        int mid = lb + (ub - lb)/2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            lb = mid + 1;
        else
            ub = mid - 1;
    }

    return lb; // index where target is found/inserted
}
