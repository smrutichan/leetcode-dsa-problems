/*
Problem: Jump Game II

Approach (Greedy):
- Maintain three variables: jumps, currentEnd and farthest

- Traverse the array:
    update farthest = max(farthest, i + nums[i])
    when i reaches currentEnd:
        increment jumps
        update currentEnd = farthest

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size()- 1; i++){
            // farthest that we can reach
            farthest = max(farthest, i + nums[i]);

            // if we reach current boundary
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
