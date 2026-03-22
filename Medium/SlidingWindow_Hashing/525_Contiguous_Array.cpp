/*
Problem: Contiguous Array

Approach:
- Treat 0 as -1 and 1 as +1
- Use prefix sum and hash map

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;  // base case
        int sum = 0, maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
