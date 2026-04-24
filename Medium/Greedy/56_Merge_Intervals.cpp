/*
Problem: Merge Intervals

Approach:
- Sort all intervals based on starting time
- Initialize result with first interval
- Traverse remaining intervals:
    - If current interval overlaps with last merged interval:
        merge by updating end = max(end, current_end)
    - Else:
        add current interval to result

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        // Start with the first interval
        result.push_back(intervals[0]);

        // Traverse remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Get last interval in result
            vector<int>& last = result.back();

            // If overlapping
            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};
