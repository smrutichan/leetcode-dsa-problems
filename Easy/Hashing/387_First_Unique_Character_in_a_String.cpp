/*
Problem: First Unique Character in a String

Approach:
- Use hashing with an unordered_map 

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;

        for(char x : s){
            freq[x]++;
        }

        for(int i = 0; i < s.length(); i++){
            if(freq[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
