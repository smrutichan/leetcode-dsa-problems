/*
Problem: Grumpy Bookstore Owner

Approach:
- Count customers already satisfied (grumpy[i] == 0)
- Use sliding window of size minutes to find max extra satisfied
- Add extra customers only where grumpy[i] == 1

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int base = 0;

    // Step 1: already satisfied
    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 0)
            base += customers[i];
    }

    // Step 2: sliding window
    int extra = 0, maxExtra = 0;

    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 1)
            extra += customers[i];

        if (i >= minutes && grumpy[i - minutes] == 1)
            extra -= customers[i - minutes];

        if (extra > maxExtra)
            maxExtra = extra;
    }
    return base + maxExtra;
}
