// problem: https://leetcode.com/problems/valid-anagram/description/

// brute (sorting)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);
    }
};
// tc: O(nlogn), sc: O(1)

// optimal (using hashing)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c-'a']++;
        }

        for (char c : t) {
            freq[c-'a']--;
        }

        for (int i=0; i<26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
// tc: O(n), sc: O(1)
