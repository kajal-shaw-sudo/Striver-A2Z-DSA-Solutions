/*
problem: You are given an integer n. You need to return the number of digits in the number.
The number will have no leading zeroes, except when the number is 0 itself.

Example 1
Input: n = 4
Output: 1
Explanation: There is only 1 digit in 4.

Example 2
Input: n = 14
Output: 2
Explanation: There are 2 digits in 14.
*/

// using string
class Solution {
public:
    int countDigit(int n) {
        return to_string(n).length();
    }
};
// tc = O(d) = O(logn) , sc = O(d) [string of length d]

// using while loop
class Solution {
public:
    int countDigit(int n) {
        if (n == 0) {
            return 1;
        }

        int count = 0;

        while (n > 0) {
            n /= 10;
            count++;
        }

        return count;
    }
};
// tc = O(d) = O(logn), sc = O(1)

// using log10
class Solution {
public:
    int countDigit(int n) {
        if (n == 0) {
            return 1;
        }

        return floor(log10(n)) + 1;
    }
};
// tc = O(1), sc = O(1)