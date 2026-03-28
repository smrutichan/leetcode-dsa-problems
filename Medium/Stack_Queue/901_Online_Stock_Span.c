/*
Problem: Online Stock Span

Approach:
- Use a monotonic decreasing stack storing (price, span)
- For each new price:
    - Initialize span = 1
    - While stack top price <= current price:
        add its span and pop
    - Push (price, span)
- Return span

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* price;
    int* span;
    int top;
    int capacity;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->capacity = 10000;
    obj->price = (int*)malloc(obj->capacity * sizeof(int));
    obj->span = (int*)malloc(obj->capacity * sizeof(int));
    obj->top = -1;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;

    while (obj->top >= 0 && obj->price[obj->top] <= price) {
        span += obj->span[obj->top];
        obj->top--;
    }

    obj->top++;
    obj->price[obj->top] = price;
    obj->span[obj->top] = span;

    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->price);
    free(obj->span);
    free(obj);
}
