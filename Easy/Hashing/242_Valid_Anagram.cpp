/*
Problem: Valid Anagram

Approach:
- Hashing using two unordered maps
- Store character frequencies of both strings and compare the maps

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){ // cannot be anagrams if the string lengths arent equal
            return false;
        }

        unordered_map<char,int> s_freq;
        unordered_map<char,int> t_freq;

        for(char x : s){
            s_freq[x]++;
        }

        for(char y : t){
            t_freq[y]++;
        }

        return s_freq == t_freq; // directly compare the two maps to check if their key value pairs are same
    }
};
