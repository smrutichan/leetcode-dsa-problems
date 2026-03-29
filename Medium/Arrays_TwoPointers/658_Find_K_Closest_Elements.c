/*
Problem: Find K Closest Elements

Approach:
- Use two pointers (left = 0, right = n-1)
- While window size > k:
    compare distance of arr[left] and arr[right] from x
    remove the element which is farther from x
- Continue shrinking window until size becomes k

Time Complexity: O(n)
Space Complexity: O(k)
*/

int* findClosestElements(int* arr, int n, int k, int x, int* returnSize) {
    int left = 0, right = n - 1;

    while (right - left + 1 > k) {
        if (abs(arr[left] - x) > abs(arr[right] - x))
            left++;
        else
            right--;
    }

    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = arr[left + i];
    }
    *returnSize = k;
    return res;
}
