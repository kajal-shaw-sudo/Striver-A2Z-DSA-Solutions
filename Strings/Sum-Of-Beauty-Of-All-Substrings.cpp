// problem: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

// approach 1: using frequency vector
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();

        int sum = 0;

        for (int i=0; i<n; i++) {
            vector<int> freq(26, 0);

            for (int j=i; j<n; j++) {
                freq[s[j] - 'a']++;

                int mini = INT_MAX, maxi = INT_MIN;
                
                for (int k=0; k<26; k++) {
                    if (freq[k] > 0) {
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};
// tc: O(n^2 * 26), sc: O(26) where n is the length of the input string

// approach 2: using unordered_map
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();

        int sum = 0;

        for (int i=0; i<n; i++) {
            unordered_map<char, int> freq;

            for (int j=i; j<n; j++) {
                freq[s[j]]++;

                int mini = INT_MAX, maxi = INT_MIN;
                
                for (auto& p : freq) {
                    mini = min(mini, p.second);
                    maxi = max(maxi, p.second);
                }

                sum += (maxi - mini);
            }
        }

        return sum;
    }
};
// tc: O(n^2 * m), sc: O(m) where n is the length of the input string and m is the number of unique characters in the input string
