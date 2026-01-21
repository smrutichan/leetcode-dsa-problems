/*
Problem: Two Sum II - Input Array Is Sorted

Approach:
- Use two pointers starting from the beginning and end of the sorted array
- Calculate the sum of the values at both pointers using binary search
- When the sum equals the target, return the 1-based indices of the two numbers

Time Complexity: O(n)
Space Complexity: O(1)
*/


 //Note: The returned array must be malloced, assume caller calls free().
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } 
        else if (sum < target) {
            left++; 
        } 
        else {
            right--;
        }
    }
    return NULL; 
}
