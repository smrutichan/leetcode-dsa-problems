/*
Problem: Jump Game

Approach:
- Use a greedy strategy to track the maximum reachable index

Time Complexity: O(n)
Space Complexity: O(1)
*/

bool canJump(int* nums, int numsSize) {
    int maxReach = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach)
            return false;

        if (i + nums[i] > maxReach)
            maxReach = i + nums[i];
    }
    return true;
}
