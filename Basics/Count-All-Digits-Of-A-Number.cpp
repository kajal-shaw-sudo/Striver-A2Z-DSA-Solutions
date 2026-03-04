// using string
class Solution {
public:
    int countDigit(int n) {
        return to_string(n).length();
    }
};

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