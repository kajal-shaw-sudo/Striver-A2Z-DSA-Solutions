// problem: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// brute
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int count = 0;

        for (int i=0; i<n; i++) {
            vector<int> freq(3);

            for (int j=i; j<n; j++) {
                freq[s[j] - 'a']++;

                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
// tc: O(n^2), sc: O(1)

// optimal: using sliding window
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> freq(3, 0);

        int count = 0, l = 0, r = 0;

        while (r < n) {
            freq[s[r] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                count += (n - r);

                freq[s[l] - 'a']--;
                l++;
            }

            r++;
        }

        return count;
    }
};
// tc: O(n), sc: O(1)