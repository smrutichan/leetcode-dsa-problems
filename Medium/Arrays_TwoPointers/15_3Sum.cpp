/*
Problem: 3Sum

Approach:
- Sort the array
- Fix one element and use two pointers to find the other two
- If sum is 0, store the triplet and skip duplicates
- If sum < 0, move left pointer right
- If sum > 0, move right pointer left
- Skip duplicate first elements to avoid repeated triplets

Time Complexity: O(n²)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicate first elements
                continue;
            if (nums[i] > 0) // Continue if number is +ve
                break;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];

                if (currSum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) // Skip duplicate left values
                        left++;

                    while (left < right && nums[right] == nums[right + 1]) // Skip duplicate right values
                        right--;
                }
                else if (currSum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
