// problem: https://leetcode.com/problems/longest-repeating-character-replacement/description/

// brute
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int maxi = 0;

        for (int i=0; i<n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;

            for (int j=i; j<n; j++) {
                freq[s[j] - 'A']++;

                maxFreq = max(maxFreq, freq[s[j] - 'A']);

                int length = j - i + 1;
                int replacements = length - maxFreq;

                if (replacements > k) {
                    break;
                }

                maxi = max(maxi, length);
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(1)

// optimal: using sliding window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int maxi = 0, l = 0, r = 0;

        vector<int> freq(26, 0);
        int maxFreq = 0;

        while (r < n) {
            freq[s[r] - 'A']++;

            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            if (((r-l+1) - maxFreq) > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxi = max(maxi, r-l+1);

            r++;
        }

        return maxi;
    }
};
// tc: O(n), sc: O(1)