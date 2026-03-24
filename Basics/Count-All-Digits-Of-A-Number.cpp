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