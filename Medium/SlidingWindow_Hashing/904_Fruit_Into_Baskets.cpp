/*
Problem: Fruit Into Baskets

Approach:
- Use sliding window + hashmap (unordered_map)
- Expand right pointer and add fruit count
- If more than 2 types → shrink from left i.e. maintain window with max 2 distinct fruits
- Track max window size

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
    int left = 0, maxLen = 0;

    for (int right = 0; right < fruits.size(); right++) {
        mp[fruits[right]]++;

        while (mp.size() > 2) {
            mp[fruits[left]]--;
            if (mp[fruits[left]] == 0)
                mp.erase(fruits[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
    }
};
