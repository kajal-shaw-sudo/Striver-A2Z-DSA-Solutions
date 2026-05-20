// problem link: https://leetcode.com/problems/fibonacci-number/description/

/*
problem: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
*/

// recursion
class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        return fib(n-1) + fib(n-2);
    }
};
// tc = O(2^n), sc = O(n) [recursion stack]

// brute iteration
class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        
        vector<int> ans(n+2, 0);
        ans[0] = 0, ans[1] = 1;

        for (int i=2; i<=n; i++) {
            ans[i] = ans[i-1] + ans[i-2];
        }

        return ans[n];
    }
};
// tc = O(n), sc = O(n) [vector]

// Optimized iteration
class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        
        int prev = 1, prev2 = 0;

        for (int i=2; i<=n; i++) {
            int curr = prev + prev2;

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
// tc = O(n), sc = O(1)