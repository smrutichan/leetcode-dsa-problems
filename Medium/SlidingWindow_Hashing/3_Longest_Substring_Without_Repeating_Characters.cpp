/*
Problem: Longest Substring Without Repeating Characters

Approach:
- Use a sliding window with two pointers to maintain a substring without duplicates
- Maintain a hash map to store the last seen index of each character
- If a character repeats within the current window, move the start pointer to one position after its last occurrence

Time Complexity: O(n)
Space Complexity: O(min(n, charset))
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= left) {
                left = mp[s[i]] + 1;
            }

            mp[s[i]] = i;
            count = max(count, i - left + 1);
        }

        return count;
    }
};
