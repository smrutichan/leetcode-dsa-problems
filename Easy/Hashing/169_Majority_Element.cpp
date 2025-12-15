/*
Problem: Majority Element

Approach:
- Use hash map to store the frequency of each element
- Return the element whose frequency exceeds n / 2

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int length = nums.size();

        for(int x: nums){
            freq[x]++;
            if(freq[x]> (length/2)){
                return x;
            }
        }
        return -1;
    }
};
