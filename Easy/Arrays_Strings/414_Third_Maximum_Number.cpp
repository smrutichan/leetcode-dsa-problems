/*
Problem: Third Maximum Number

Approach:
- Sort array in d.o. and count distinct elements while traversing
- Return the 3rd distinct max if present, otherwise return the max

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int distinctCount = 1;
        for (int i = 1; i < nums.size(); i++) {
            // Count only distinct nums
            if (nums[i] != nums[i - 1]) {
                distinctCount++;
                if (distinctCount == 3)
                    return nums[i];
            }
        }
        // If 3rd distinct max doesn't exist
        return nums[0];
    }
};
