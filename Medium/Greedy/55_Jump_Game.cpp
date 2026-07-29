/*
Problem: Jump Game

Approach:
- Use a greedy strategy to track the maximum reachable index

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest)
                return false;
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};
