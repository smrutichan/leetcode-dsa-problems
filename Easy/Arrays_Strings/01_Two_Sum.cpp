/*
Data Structure Used: unordered_map
Time Complexity: O(n)
Space Complexity: O(1) 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        // Store each number and its index
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        // Find the complement
        for (int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];

            if (mp.find(val) != mp.end() && mp[val] != i) {
                return {i, mp[val]};
            }
        }

        return {};
    }
};
