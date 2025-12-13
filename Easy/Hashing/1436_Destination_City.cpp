/*
Problem: Destination City

Approach:
- Hashing using an unordered set
- Store all source cities and find the destination city not present in the set

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sources;

        //Store all source cities
        for (auto &p : paths) {
            sources.insert(p[0]);
        }
        //Find destination not present in sources
        for (auto &p : paths) {
            if (sources.find(p[1]) == sources.end()) {
                return p[1];
            }
        }
        return "";
    }
};
