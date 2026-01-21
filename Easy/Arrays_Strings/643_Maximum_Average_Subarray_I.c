/*
Problem: Maximum Average Subarray I

Approach:
- Compute the sum of the first k elements as the initial window
- Slide the window by adding the next element and removing the element leaving the window
- Track the maximum window sum and compute the average at the end

Time Complexity: O(n)
Space Complexity: O(1)
*/

double findMaxAverage(int* nums, int numsSize, int k) {
    int windowSum = 0;
    // Sum of first k elements
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < numsSize; i++) {
        windowSum += nums[i];        // add new element
        windowSum -= nums[i - k];    // remove element leaving window

        if (windowSum > maxSum)
            maxSum = windowSum;
    }
    return (double)maxSum / k;
}
