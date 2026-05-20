/*
problem: You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.
A prime number is a number which has no divisors except 1 and itself.

Example 1
Input: n = 5
Output: true
Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

Example 2
Input: n = 8
Output: false
Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.
*/

// brute 1
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }

        for (int i=2; i<n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
};
// tc = O(n) , sc = O(1)

// brute 2
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        
        int count = 0;

        for (int i=1; i<=n; i++) {
            if (n % i == 0) {
                count++;
            }
        }

        return (count == 2);
    }
};

// Optimal 1
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        
        int count = 0;

        for (int i=1; i*i<=n; i++) {
            if (n % i == 0) {
                count++;

                // if n is not a perfect square, count its reciprocal factor
                if (n / i != i) {
                    count++;
                }
            }
        }

        return (count == 2);
    }
};
// tc = O(sqrt(n)) , sc = O(1)

// Optimal 2
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;  // early exit
    }

        return true;
    }
};
// tc = O(sqrt(n)) , sc = O(1)