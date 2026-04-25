/*
problem: Given a string s and an integer k.Find the length of the longest substring with at most k distinct characters.

Example 1

Input : s = "aababbcaacc" , k = 2
Output : 6

Explanation : The longest substring with at most two distinct characters is "aababb".
The length of the string 6.
*/

// brute: generate all substrings
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();

        int maxi = 0;

        for (int i=0; i<n; i++) {
            unordered_map<int, int> freq;

            for (int j=i; j<n; j++) {
                freq[s[j]]++;

                if (freq.size() > k) {
                    break;
                }

                maxi = max(maxi, j-i+1);
            }
        }

        return maxi;
    }
};
// tc: O(n^2) sc: O(k)

// optimal: sliding window
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();

        int maxi = 0;

        unordered_map<int, int> freq;

        int left = 0, right = 0;

        while (right < n) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            maxi = max(maxi, right-left+1);

            right++;
        }


        return maxi;
    }
};
// tc: O(n) sc: O(k)