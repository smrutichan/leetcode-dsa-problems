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
        unordered_map<char, int> seen;
        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            if (seen.count(s[i]) && seen[s[i]] >= start) {
                start = seen[s[i]] + 1;
            }
            
            seen[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};
