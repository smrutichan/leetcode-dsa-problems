/*
Problem: Move Zeroes

Approach:
- Two-pointer technique
- Move all non-zero elements forward while preserving order and fill remaining positions with 0s

Time Complexity: O(n)
Space Complexity: O(1)
*/

void moveZeroes(int* nums, int numsSize) {
    int k = 0;
    // move all non-zero elements forward
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[k] = nums[i];
            k++;
        }
    }
    // fill the remaining array with 0s
    while(k < numsSize){
        nums[k] = 0;
        k++;
    }
}
