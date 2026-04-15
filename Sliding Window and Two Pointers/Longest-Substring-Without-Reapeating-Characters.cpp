// problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// brute
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int maxi = 0;

        for (int i=0; i<n; i++) {
            unordered_set<int> seen;

            for (int j=i; j<n; j++) {
                if (seen.count(s[j])) {
                    break;
                }

                seen.insert(s[j]);
                
                maxi = max(maxi, j-i+1);
            }
        }

        return maxi;
    }
};
// tc: O(n^2), sc: O(min(m, n)) where m is the size of charset

// optimal: using sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int maxi = 0, l = 0, r = 0;

        vector<int> hash(256, -1);

        while (r < n) {
            if (hash[s[r]] != -1) {
                l = max(l, hash[s[r]] + 1);
            }

            maxi = max(maxi, r-l+1);

            hash[s[r]] = r;

            r++;
        }

        return maxi;
    }
};
// tc: O(n), sc: O(min(m, n)) where m is the size of charset