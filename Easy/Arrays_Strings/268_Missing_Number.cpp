/*
Problem: Missing Number

Approach:
- There are n numbers in range [0, n]
- Calculate expected sum of numbers from 0 to n using: total = n * (n + 1) / 2
- Calculate actual sum of given array
- Missing number = total - actual sum

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2; // sum from 1 to n
        int sum = 0;

        for(int x : nums){
            sum += x;
        }

        return total - sum; // missing number
    }
};
