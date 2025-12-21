/*
Problem: Guess Number Higher or Lower

Approach:
- Binary search on the range from 1 to n

Time Complexity: O(log n)
Space Complexity: O(1)
*/

// Forward declaration of the guess API
int guess(int num);

int guessNumber(int n) {
    int low = 1;
    int high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = guess(mid);

        if (res == 0) {
            return mid;
        } else if (res == -1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; 
}
