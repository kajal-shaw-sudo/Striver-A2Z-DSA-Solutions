// problem: https://leetcode.com/problems/roman-to-integer/description/

// brute: create a map of roman numerals and their corresponding integer values and iterate through the string to calculate the integer value
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();

        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = 0;

        for (int i=0; i<n-1; i++) {
            if (roman[s[i]] < roman[s[i+1]]) {
                ans -= roman[s[i]];
            }

            else {
                ans += roman[s[i]];
            }
        }

        // add the last value to ans as there is nothing to compare further
        return ans + roman[s[n-1]];
    }
};
// tc: O(n), sc: O(1) where n is the length of the input string