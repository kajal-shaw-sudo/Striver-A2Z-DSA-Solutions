/*
problem: Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

Example 1
Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.

Example 2
Input: N = 4, M = 69
Output:-1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

// brute: linear search from 1 to M, return i if i^N == M exactly, else -1
class Solution {
private:
    // helper function which computes base^exponent in O(N) using repeated multiplication, with early exit if result exceeds limit to prevent overflow
    long long computePower(long long base, long long exponent, long long limit) {
        long long ans = 1;

        for (int i=0; i<exponent; i++) {
            ans *= base;

            if (ans > limit) {
                return ans;
            }
        }

        return ans;
    }

public:
  int NthRoot(int N, int M) {
       for (int i=1; i<=M; i++) {
        long long power = computePower(i, N, M);

        if (power == M) {
            return i;
        }

        else if (power > M) {
            break;
        }
       }

       return -1;
    }
};
// tc: O(M * N) [where N is the time to compute i^N], sc: O(1)

// optimal: using binary search from 1 to M, return i if i^N == M exactly, else -1
class Solution {
private:
    // helper function which computes base^exponent in O(N) using repeated multiplication, with early exit if result exceeds limit to prevent overflow
    long long computePower(long long base, long long exponent, long long limit) {
        long long ans = 1;

        for (int i=0; i<exponent; i++) {
            ans *= base;

            if (ans > limit) {
                return ans;
            }
        }

        return ans;
    }

public:
  int NthRoot(int N, int M) {
       int low = 1, high = M;

       while (low <= high) {
        int mid = low + (high - low) / 2;

        long long power = computePower(mid, N, M);

        if (power == M) {
            return mid;
        }

        else if (power < M) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
       }

       return -1;
    }
};
// tc: O(log(M) * N) [where N is the time to compute i^N], sc: O(1)
