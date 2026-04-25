/*
problem: Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.
If there is no such window in s1 that covers all characters in s2, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1

Input: s1 = "abcdebdde", s2 = "bde"
Output: "bcde"
Explanation:
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of s2 in the window must occur in order.
*/

// brute: generate all substrings and check if they contain s2 as a subsequence
class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        if (m < n) {
            return "";
        }

        int minLength = 1e9, startIndex = -1;

        for (int i=0; i<m; i++) {
            int k = 0; // pointer for s2

            for (int j=i; j<m; j++) {
                if (s1[j] == s2[k]) {
                    k++; // match next of t in order
                }

                if (k == n) {
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

        return s1.substr(startIndex, minLength);
    }
};
// tc: O(m^2) sc: O(1)

// optimal: two-pass — forward pass greedily finds the tightest right end where s2 is matched as a subsequence from i, then backward pass shrinks from that end to find the tightest left start; i jumps to start+1
class Solution {
public:
    string minWindow(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        if (m < n) {
            return "";
        }

        int minLength = 1e9, startIndex = -1;

        int i = 0;

        while (i < m) {
            // forward pass: find tightest right end from i
            int j = 0, end = i;

            while (end < m && j < n) {
                if (s1[end] == s2[j]) {
                    j++;
                }

                end++;
            }

            if (j < n) {
                break;
            }

            end--;

            // backward pass: find tightest left start from end
            int back = n-1, start = end;

            while (back >= 0) {
                if (s1[start] == s2[back]) {
                    back--;
                }

                start--;
            }

            start++;

            if ((end-start+1) < minLength) {
                minLength = end-start+1;
                startIndex = start;
            }

            i = start + 1;
        }

        if (startIndex == -1) {
            return "";
        }

        return s1.substr(startIndex, minLength);
    }
};
// tc: O(m²) worst case, but faster in practice as i jumps to start+1 instead of advancing one step at a time; sc: O(1)

/*
s1 = "abcdeabcde", s2 = "ace"

Brute:   i = 0, 1, 2, 3, 4, 5...   (every index)
Optimal: i = 0 → start+1 = 2 → start+1 = 7...  (big jumps)
*/
