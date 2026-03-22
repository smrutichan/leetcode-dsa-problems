/*
Problem: Daily Temperatures

Approach:
- Use a monotonic decreasing stack (store indices)
- While current temperature > stack top → resolve previous days
- Pop and calculate days waited

Time Complexity: O(n)
Space Complexity: O(n)
*/

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* ans = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && temps[i] > temps[stack[top]]) {
            int prev = stack[top--];
            ans[prev] = i - prev;
        }
        stack[++top] = i;
    }

    free(stack);
    return ans;
}
