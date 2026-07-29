/*
Problem: Product of Array Except Self

Approach:
- Compute prefix product for each index and store it in the answer array
- Traverse from right to left to compute suffix product
- Multiply each answer[i] by the corresponding suffix product
- Return the final array

Time Complexity: O(n)
Space Complexity: O(1) (excluding output array)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // array of 1s with length = n

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};
