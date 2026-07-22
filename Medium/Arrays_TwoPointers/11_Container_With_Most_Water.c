/*
Problem: Container With Most Water

Approach:
- Use two pointers starting at the leftmost and rightmost indices
- The height of the container is limited by the shorter line
- Move the pointer pointing to the shorter line inward to potentially increase area

Time Complexity: O(n)
Space Complexity: O(1)
*/

int maxArea(int* height, int heightSize) {
    int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxArea;
}
