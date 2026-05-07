/*
problem: Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

Example 1

Input: n = 36
Output: 6
Explanation: 6 is the square root of 36.

Example 2

Input: n = 28
Output: 5
Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.
*/

// brute: linear search from 1 to n, return the largest i such that i*i <= n
class Solution {
public:
    int floorSqrt(int n)  {
      int ans = 0;

      for (int i=1; i<=n; i++) {
        if ((long long)i * i <= n) {
            ans = i;
        }

        else {
            // break when i * i > n
            break;
        }
      }

      return ans;
    }
};
// tc: O(sqrt(n)), sc: O(1)

// optimaized: using binary search from 1 to n, return the largest i such that i*i <= n
class Solution {
public:
    int floorSqrt(int n)  {
        int ans = 0;

        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if ((long long)mid * mid <= n) {
                ans = mid;
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
// tc: O(log(n)), sc: O(1)

// optimal: using built-in sqrt function
class Solution {
public:
    int floorSqrt(int n)  {
      int ans = (int)sqrt((double)n);

      // adjust for floating point error
      while ((long long)(ans + 1) * (ans + 1) <= n) {
        ans++;
      }

      while ((long long)ans * ans > n) {
        ans--;
      } 

      return ans;
    }
};
// tc: O(1), sc: O(1)
// note: Both while loops are O(1) because floating point error in sqrt() is at most ±1, so each loop runs at most 1–2 iterations regardless of how large n is. They're just a safety net, not a real loop.