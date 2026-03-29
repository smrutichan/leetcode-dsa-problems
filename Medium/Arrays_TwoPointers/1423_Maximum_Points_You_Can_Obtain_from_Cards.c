/*
Problem: Maximum Points You Can Obtain from Cards

Approach:
- Take first k elements from left
- Then gradually replace elements from left with elements from right
- Track maximum sum

Time Complexity: O(k)
Space Complexity: O(1)
*/

int maxScore(int* arr, int n, int k) {
    int leftSum = 0;

    // take first k elements
    for (int i = 0; i < k; i++)
        leftSum += arr[i];

    int maxSum = leftSum;
    int rightSum = 0;
    // replace from right
    for (int i = 0; i < k; i++) {
        leftSum -= arr[k - 1 - i];
        rightSum += arr[n - 1 - i];

        int total = leftSum + rightSum;
        if (total > maxSum)
            maxSum = total;
    }
    return maxSum;
}
