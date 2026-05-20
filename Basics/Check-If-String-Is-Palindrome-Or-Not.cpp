// problem: https://leetcode.com/problems/valid-palindrome/description/

/*
problem: A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

// recursion
class Solution {
private:
    bool helper(string& str, int i) {
        if (i >= str.size() / 2) {
            return true;
        }

        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }

        return helper(str, i + 1);
    }

public:
    bool isPalindrome(string s) {
        string alphanum = "";

        for (char c : s) {
            if (isalnum(c)) {
                alphanum += tolower(c);
            }
        }

        return helper(alphanum, 0);
    }
};
// tc = O(n) [loop] + O(n) [recursion] = O(n) , sc = O(n) [alphanum string]

// 2 pointers
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;

        while (l <= r) {
            if (!isalnum(s[l])) {
                l++;
            }

            else if (!isalnum(s[r])) {
                r--;
            }

            else if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            else {
                l++, r--;
            }
        }

        return true;
    }
};
// tc = O(n), sc = O(1)