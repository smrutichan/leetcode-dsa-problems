/*
Problem: Assign Cookies

Approach:
- Sort the greed and cookie size arrays using qsort
- Greedily assign the smallest sufficient cookie to each child using two pointers

Time Complexity: O(n log n)
Space Complexity: O(1)

Note:
- qsort is used because it gives the least time complexity amongst all sorting functions
*/

#include <stdlib.h>

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // Sort both arrays in ao
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    int i,j,contentChildren = 0;
    while(i < gSize && j < sSize){
        if(s[j] >= g[i]){
            i++;
            j++;
            contentChildren++;
        }
        else {
            j++; // Move on to the next cookie size for the same child
        }
    }
    return contentChildren;
}
