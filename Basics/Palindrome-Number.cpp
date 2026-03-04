// brute
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long long dup = x;
        long long rev = 0;

        while (dup != 0) {
            long long last = dup % 10;
            dup /= 10;
            rev = rev * 10 + last;
        }

        return (x == (int)rev);
    }
};

// optimized
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            // rev only half of the number, if the first half is equal to the second half, then it's a palindrome
            return false;
        }
        
        long long revHalf = 0;

        while (x > revHalf) {
            long long last = x % 10;
            x /= 10;
            revHalf = revHalf * 10 + last;
        }

        return (x == (int)revHalf || x == (int)revHalf/10);
    }
};