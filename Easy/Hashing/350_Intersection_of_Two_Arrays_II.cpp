/*
Problem: Intersection of Two Arrays II

Approach:
- Use hash map to store frequency of elements from the 1st array
- Traverse the 2nd array and add elements to the result(if it exists in map) while decrementing frequency

Time Complexity: O(n + m)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq_nums1;
        vector<int> result;

        for(int x : nums1){
            freq_nums1[x]++;
        }

        for(int y : nums2){
            if(freq_nums1[y] > 0){
                result.push_back(y); // in-built method to add an element to the array
                freq_nums1[y]--;
            }
        }
        return result;
    }
};
