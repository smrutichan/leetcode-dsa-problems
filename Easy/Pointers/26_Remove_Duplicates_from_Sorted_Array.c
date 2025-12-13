/*
Problem: Remove Duplicates from Sorted Array

Approach:
- Array-based technique with linear search
- Store unique elements in a temporary array and copy them back

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

bool is_in(int* arr, int size, int value){
    for(int i = 0; i < size; i++){
        if(arr[i] == value){
            return true;
        }
    }
    return false;
}

int removeDuplicates(int* nums, int numsSize) {
    int expectedNums[numsSize];
    int k = 0;

    expectedNums[0] = nums[0];
    k = 1;

    for(int i = 1; i < numsSize; i++){
        if(is_in(expectedNums,k,nums[i]) == false){
            expectedNums[k] = nums[i];
            k = k + 1;
        }
    }

    for(int i = 0; i < k; i++){
        nums[i] = expectedNums[i];
    }
    return k;
}
