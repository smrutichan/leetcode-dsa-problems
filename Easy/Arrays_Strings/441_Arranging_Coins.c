/*
Problem: Arranging Coins

Approach:
- Use binary search on the number of complete rows
- Check how many coins are needed to form k rows using k(k+1)/2
- Find the maximum k such that the required coins do not exceed n

Time Complexity: O(log n)
Space Complexity: O(1)
*/

int arrangeCoins(int n) {
    long lb = 0;
    long ub = n;
    long k;

    while(lb <= ub){
        long mid = lb + (ub - lb) / 2;
        long k = mid *(mid + 1) / 2;

        if(k == n){
            return mid;
        }
        else if(k > n){
            ub = mid - 1;
        }
        else {
            lb = mid + 1;
        }
    }
    return ub;
}
