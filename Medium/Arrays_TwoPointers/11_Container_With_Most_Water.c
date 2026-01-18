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
    int right = heightSize - 1;
    int maxWater = 0;

    while(left < right){
        int h = height[left] < height[right] ? height[left] : height[right]; // to decide which line to take as final height for finding area
        int width = right - left;
        int area = width * h;

        if(area > maxWater){
            maxWater = area;
        }

        if(height[left] < height[right]){
            left++;
        }
        else {
            right--;
        }
    }
    return maxWater;
}
