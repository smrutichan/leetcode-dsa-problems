/*
Problem: Daily Temperatures

Approach:
- Use a monotonic decreasing stack (store indices)
- While current temperature > stack top → resolve previous days
- Pop and calculate days waited

Time Complexity: O(n)
Space Complexity: O(n)
*/

int* dailyTemperatures(int* arr, int n, int* returnSize) {
    *returnSize = n;
    int* ans = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[i] > arr[stack[top]]) {
            int prev = stack[top--];
            ans[prev] = i - prev;
        }
        stack[++top] = i;
    }

    free(stack);
    return ans;
}
