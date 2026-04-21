// problem: https://leetcode.com/problems/longest-palindromic-substring/description/

// brute (for-loops)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        string longest = "";

        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                string temp = s.substr(i, j-i+1);

                string rev = temp;
                reverse(rev.begin(), rev.end());

                if (temp == rev && temp.size() > longest.size()) {
                    longest = temp;
                }
            }
        }

        return longest;
    }
};
// tc: O(n^3), sc: O(n)

// optimal (expand around center)
class Solution {
private:
    int expandFromCenter(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--, right++;
        }

        return (right-left-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n == 0) {
            return "";
        }

        int start = 0, end = 0;
        int maxLength = 1;
        
        for (int center=0; center<n; center++) {
            int oddLength = expandFromCenter(s, center, center);
            int evenLength = expandFromCenter(s, center, center+1);

            maxLength = max(oddLength, evenLength);

            if (maxLength > (end-start)) {
                start = center - (maxLength-1)/2;
                end = center + maxLength/2;
            }
        }

        return s.substr(start, end-start+1);
    }
};
// tc: O(n^2), sc: O(1)