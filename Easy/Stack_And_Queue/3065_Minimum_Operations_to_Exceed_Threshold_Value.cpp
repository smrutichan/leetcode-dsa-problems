/*
Problem: Minimum Operations to Make Array Elements >= k

Approach:
- Use a min-heap (priority_queue) to always access the smallest element
- Repeatedly remove the smallest element while it is less than k
- Count the number of removals performed

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert all elements into heap
        for (int x : nums) {
            pq.push(x);
        }

        int count = 0;
        // Remove smallest elements until condition is met
        while (!pq.empty() && pq.top() < k) {
            pq.pop();
            count++;
        }
        return count;
    }
};
