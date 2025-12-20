/*
Problem: Word Pattern

Approach:
- Use two hash maps to maintain a bijection
- Map pattern characters to words and words back to pattern characters

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ps_map;   // pattern -> string
        unordered_map<string, char> sp_map;   // string -> pattern

        vector<string> words;
        string word;
        stringstream ss(s);

        // Split s into words
        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.length() != words.size()) // if string and pattern arent of same length, return false
            return false;

        for (int i = 0; i < pattern.length(); i++) {
            char p = pattern[i];
            string w = words[i];

            if (ps_map.count(p) && ps_map[p] != w)
                return false;
            if (sp_map.count(w) && sp_map[w] != p)
                return false;

            ps_map[p] = w;
            sp_map[w] = p;
        }
        return true;
    }
};
