/*
Problem: Contains Duplicate

Approach:
- Use hashing to store elements as they are traversed
- If an element already exists in the hash set, a duplicate is found

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int x : nums) {
            if (seen.count(x) > 0) {   // Element already exists
                return true;
            }
            seen.insert(x); // Insert element into 'seen' for future use
        }
        return false;
    }
};
