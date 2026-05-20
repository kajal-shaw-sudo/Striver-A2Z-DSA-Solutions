/*
problem: You are given an integer n. Return the value of n! or n factorial.
Factorial of a number is the product of all positive integers less than or equal to that number.

Example 1
Input: n = 2
Output: 2
Explanation: 2! = 1 * 2 = 2.

Example 2
Input: n = 0
Output: 1
Explanation: 0! is defined as 1.
*/

class Solution {
public:
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        }

        return n * factorial(n-1);
    }
};
// tc = O(n), sc = O(n) [stack]
