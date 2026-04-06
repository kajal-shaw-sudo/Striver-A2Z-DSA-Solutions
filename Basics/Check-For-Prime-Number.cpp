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
bool isPrime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;  // early exit
    }

    return true;
}
// tc = O(sqrt(n)) , sc = O(1)