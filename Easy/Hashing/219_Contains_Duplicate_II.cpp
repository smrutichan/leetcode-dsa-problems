/*
Problem: Contains Duplicate II

Approach:
- Use hashing to store the last index where each element was found while traversing the array
- If the same element is found again and the index difference is ≤ k, return true

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            // If element seen before
            if (lastIndex.count(nums[i]) > 0) {
                if (i - lastIndex[nums[i]] <= k) {
                    return true;
                }
            }
            // Update last index
            lastIndex[nums[i]] = i;
        }
        return false;
    }
};
