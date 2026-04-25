// problem link: https://leetcode.com/problems/minimum-window-substring/description/

/*
problem: Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

// brute: generate all substrings and check if they contain all characters of t
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        if (m < n) {
            return "";
        }

        int minLength = 1e9, startIndex = -1;

        for (int i=0; i<m; i++) {
            vector<int> hash(256, 0);

            int count = 0;

            for (int j=0; j<n; j++) {
                hash[t[j]]++;
            }

            for (int j=i; j<m; j++) {
                if (hash[s[j]] > 0) {
                    count++;
                }

                hash[s[j]]--;

                if (count == n) {
                    if ((j-i+1) < minLength) {
                        minLength = j-i+1;
                        startIndex = i;
                    }

                    break;
                }
            }
        }

        if (startIndex == -1) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};
// tc: O(m^2) sc: O(1)

// optimal: sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();

        if (m < n) {
            return "";
        }

        int minLength = 1e9, startIndex = -1;

        int left = 0, right = 0;

        vector<int> hash(256, 0);

        for (char& c : t) {
            hash[c]++;
        }

        int count = 0;

        while (right < m) {
            if (hash[s[right]] > 0) {
                count++;
            }

            hash[s[right]]--;

            while (count == n) {
                if ((right-left+1) < minLength) {
                    minLength = right-left+1;
                    startIndex = left;
                }

                hash[s[left]]++;

                if (hash[s[left]] > 0) {
                    count--;
                }

                left++;
            }

            right++;
        }

        if (startIndex == -1) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};
// tc: O(m+n) sc: O(1)
