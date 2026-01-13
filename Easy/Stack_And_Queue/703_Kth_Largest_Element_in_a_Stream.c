/*
Problem: Kth Largest Element in a Stream

Approach:
- Maintain a min heap of size k to store the k largest elements seen so far
- When a new element is added, update the heap if it belongs in the top k
- The smallest element in the heap represents the kth largest value

Time Complexity: O(log k) per insertion
Space Complexity: O(k)
*/

#include <stdlib.h>

// Structure for KthLargest
typedef struct {
    int* heap;      // min heap
    int size;       // current size of heap
    int capacity;   // k
} KthLargest;

// Swap helper
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (after insertion)
void heapifyUp(KthLargest* obj, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (obj->heap[parent] <= obj->heap[index])
            break;
        swap(&obj->heap[parent], &obj->heap[index]);
        index = parent;
    }
}

// Heapify down (after removal)
void heapifyDown(KthLargest* obj, int index) {
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;
        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&obj->heap[index], &obj->heap[smallest]);
        index = smallest;
    }
}

// Create object
KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->capacity = k;

    for (int i = 0; i < numsSize; i++) {
        // Reuse add logic
        if (obj->size < k) {
            obj->heap[obj->size++] = nums[i];
            heapifyUp(obj, obj->size - 1);
        } else if (nums[i] > obj->heap[0]) {
            obj->heap[0] = nums[i];
            heapifyDown(obj, 0);
        }
    }
    return obj;
}

// Add value and return kth largest
int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->capacity) {
        obj->heap[obj->size++] = val;
        heapifyUp(obj, obj->size - 1);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }
    return obj->heap[0];
}

// Free memory
void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}
