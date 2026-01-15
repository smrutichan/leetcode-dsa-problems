/*
Problem: Relative Ranks

Approach:
- Use a max heap to store each athlete’s score along with their original index
- Repeatedly extract the highest score from the heap
- Assign medals to the top three athletes and numeric ranks to the rest

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        // Max heap: (score, original index)
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; i++) {
            maxHeap.push({score[i], i});
        }

        vector<string> answer(n);
        int rank = 1;
        // Pop elements from heap in descending order
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int index = top.second;

            if (rank == 1)
                answer[index] = "Gold Medal";
            else if (rank == 2)
                answer[index] = "Silver Medal";
            else if (rank == 3)
                answer[index] = "Bronze Medal";
            else
                answer[index] = to_string(rank);

            rank++;
        }
        return answer;
    }
};
