/*
Problem: Remove Element

Approach:
- Array traversal with in-place overwriting
- Shift elements not equal to the given value to the front

Time Complexity: O(n)
Space Complexity: O(1)
*/

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
