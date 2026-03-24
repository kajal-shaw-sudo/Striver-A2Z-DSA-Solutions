// problem: https://leetcode.com/problems/valid-palindrome/description/

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