/*
Problem: Divide Players Into Teams of Equal Skill

Approach:
- Calculate total sum of skills
- Each pair must sum to target = total / (n/2)
- Use hashmap to count frequencies
- For each skill x:
    find partner = target - x
    match frequencies
- Add product for each valid pair

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n = skill.size();
        long long sum = 0;

        for (int x : skill)
            sum += x;

        int teams = n / 2;

        if (sum % teams != 0) return -1;
        int target = sum / teams;

        unordered_map<int, int> freq;

        for (int x : skill)
            freq[x]++;

        long long ans = 0;

        for (auto& p : freq) {
            int x = p.first;
            int count = p.second;
            int y = target - x;

            if (freq[y] != count)
                return -1;

            if (x == y) {
                ans += (long long)x * y * (count / 2);
            } else if (x < y) {
                ans += (long long)x * y * count;
            }
        }

        return ans;
    }
};
