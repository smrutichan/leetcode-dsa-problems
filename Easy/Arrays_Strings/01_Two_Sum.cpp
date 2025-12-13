/*
Data Structure Used: Array
Time Complexity: O(n^2)
Space Complexity: O(1) (excluding output array)

Note:
This is a brute-force solution using arrays.
An optimized O(n) solution can be achieved using hashing.
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for(int i = 0; i < numsSize-1; i++){
        for(int j = i+1; j < numsSize; j++){
            if((nums[i] + nums[j]) == target){
                result[0] = i;
                result[1] = j;
            }
        }
    }
    return result;
}
