// problem: https://leetcode.com/problems/longest-common-prefix/description/

// brute: compare the prefix with each string and keep reducing the prefix until it matches with all strings
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        string prefix = strs[0];

        for (int i=1; i<n; i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size()-1);

                if (prefix.empty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
};
// tc: O(n*m), sc: O(1) where m is the length of the longest common prefix

// optimal: sort the array and compare the first and last strings
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if (n == 0) {
            return "";
        }

        sort(strs.begin(), strs.end());
        
        string first = strs[0], last = strs[n-1];

        int minLength = first.size();

        string ans = "";

        for (int i=0; i<minLength; i++) {
            if (first[i] != last[i]) {
                break;
            }

            ans += first[i];
        }

        return ans;
    }
};
// tc: O(nlogn + m), sc: O(1) where m is the length of the longest common prefix
