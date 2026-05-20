// problem link: https://leetcode.com/problems/reverse-integer/description/

/*
problem: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        int dup = x;
        int rev = 0;

        while (dup != 0) {
            int last = dup % 10;
            dup /= 10;

            if ((rev > (INT_MAX / 10)) || (rev == (INT_MAX / 10) && last > 7)) {
                return 0;
            }

            if ((rev < (INT_MIN / 10)) || (rev == (INT_MIN / 10) && last < -8)) {
                return 0;
            }

            rev = rev * 10 + last;
        }

        return rev;
    }
};
// tc = O(d) = O(logn), sc = O(1)