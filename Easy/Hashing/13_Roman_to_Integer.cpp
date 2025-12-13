/*
Problem: Roman to Integer

Approach:
- Hashing using an unordered map
- Compare current and next symbol values to handle subtraction cases

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int len = s.size();

        for(int i = 0; i < len; i++){
            if(i+1 < len && value[s[i]] < value[s[i+1]]){
                total -= value[s[i]];
            }
            else {
                total += value[s[i]];
            }
        }
        return total;
    }
    
};
