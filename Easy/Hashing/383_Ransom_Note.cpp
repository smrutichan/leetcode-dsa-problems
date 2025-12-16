/*
Problem: Ransom Note

Approach:
- Use a hash map to count the frequency of each character in the magazine
- For each character in the ransom note, reduce its count from the map
- If any character is unavailable, return false

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        // Step 1: count characters in magazine
        for (char c : magazine) {
            freq[c]++;
        }
        // Step 2: check ransomNote
        for (char c : ransomNote) {
            if (freq[c] == 0) {
                return false;
            }
            freq[c]--;
        }
        return true;
    }
};
