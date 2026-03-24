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