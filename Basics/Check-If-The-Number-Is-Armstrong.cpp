// using pow stl
class Solution {
public:
    bool isArmstrong(int n) {
        int size = to_string(n).length();

        int sum = 0;

        int dup = n;

        while (dup != 0) {
            int last_digit = dup % 10;
            dup /= 10;
            sum += (int)pow(last_digit, size);
        }

        return (n == sum);
    }
};
// tc = O(size) = O(d) = O(logn), where size is the number of digits in n and pow function takes O(1) time, so overall O(size)
// sc = O(size) = O(d) = O(logn) [to_string(n) allocates a string of length d]

// without using pow stl (safest way)
class Solution {
public:
    bool isArmstrong(int n) {
        int size = to_string(n).length();

        int sum = 0;

        int dup = n;

        while (dup != 0) {
            int last_digit = dup % 10;
            dup /= 10;

            int power = 1;
            for (int i=0; i<size; i++) {
                power *= last_digit;
            }
            sum += power;
        }

        return (n == sum);
    }
};
// tc = O(size^2) = O(d^2) = O(log^2 n), where size is the number of digits in n
// sc = O(size) = O(d) = O(logn) [to_string(n) allocates a string of length d]