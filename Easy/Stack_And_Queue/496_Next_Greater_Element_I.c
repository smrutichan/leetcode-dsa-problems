/*
Problem: Next Greater Element I

Approach:
- Use a monotonic decreasing stack to process nums2
- Use that information to build the result for the first array.

Time Complexity: O(n)
Space Complexity: O(n)
*/

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* result = (int*)malloc(nums1Size * sizeof(int));

    int stack[nums2Size];
    int top = -1;

    // Map: value -> next greater value
    int nextGreater[10001];
    for (int i = 0; i < 10001; i++)
        nextGreater[i] = -1;

    // Build next greater mapping using stack
    for (int i = 0; i < nums2Size; i++) {
        while (top >= 0 && nums2[i] > stack[top]) {
            nextGreater[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = nums2[i];
    }

    for (int i = 0; i < nums1Size; i++) {
        result[i] = nextGreater[nums1[i]];
    }
    return result;
}
