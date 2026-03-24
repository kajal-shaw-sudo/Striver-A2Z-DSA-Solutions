// problem: https://leetcode.com/problems/palindrome-number/description/

// using only string
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string s = to_string(x);
        string t = s;

        reverse(t.begin(), t.end());

        return (s == t);
    }
};
// tc = O(d) [to_string functon] + O(d) [copy t = s] + O(d) [reverse] = O(d) = O(logn), sc = O(d) [2 strings]
// sc = O(d) + O(d) [2 strings: s and t] = O(d)

// using reverse string stl
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string s = to_string(x);
        reverse(s.begin(), s.end());

        return (stoll(s) == x);
    }
};
// tc = O(d) [to_string()] + O(d) [reverse] + O(d) [stoll] = O(d)
// sc = O(d) [1 string: s]

//using string 2 pointers
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        int l = 0, r = s.size()-1;

        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }

            l++, r--;
        }

        return true;
    }
};
// tc = O(d) [to_string()] + O(d/2) [2 pointer loop at most d/2 iterations] = O(d) = O(logn)
// sc = O(d) [1 string: s]

// using reverse number logic
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long dup = x, rev = 0;

        while (dup != 0) {
            long long last = dup % 10;
            dup /= 10;
            rev = rev * 10 + last;
        }

        return (rev == x);
    }
};
// tc = O(logn) = O(d), sc = O(1)

// optimized
class Solution {
public:
    bool isPalindrome(int x) {
        // if x is neg OR the last digit is 0(e.g., 120 -> rev = 021 : not palindrome)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        } 

        long long revHalf = 0;

        while (x > revHalf) {
            int last = x % 10;
            x /= 10;
            revHalf = revHalf * 10 + last; 
        }

        // compare x with revHalf for even-length palindromes and with revHalf / 10 for odd-length palindromes since middle element doesn't need to match with anyone
        return (x == revHalf || x == (revHalf / 10));
    }
};
// tc = O(d/2) = O(d) = O(logn), sc = O(1)