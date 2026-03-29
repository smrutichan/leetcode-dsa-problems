/*
Problem: Arithmetic Slices

Approach:
- Check if current 3 elements form arithmetic sequence
- If yes → extend previous count
- Keep track of current
- Add current to result

Time Complexity: O(n)
Space Complexity: O(1)
*/

int numberOfArithmeticSlices(int* nums, int n) {
    int count = 0;
    int curr = 0;

    for (int i = 2; i < n; i++) {
        if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            curr++;          // extend previous slices
            count += curr;   // add all new slices
        } else {
            curr = 0;
        }
    }
    return count;
}
