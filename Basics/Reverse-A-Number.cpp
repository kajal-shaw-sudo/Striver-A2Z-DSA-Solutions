class Solution {
public:
    int reverse(int x) {
        int dup = x;
        int rev = 0;

        while (dup != 0) {
            int last = dup % 10;
            dup /= 10;

            if ((rev > (INT_MAX / 10)) || (rev == (INT_MAX / 10) && last > 7)) {
                return 0;
            }

            if ((rev < (INT_MIN / 10)) || (rev == (INT_MIN / 10) && last < -8)) {
                return 0;
            }

            rev = rev * 10 + last;
        }

        return rev;
    }
};
// tc = O(d) = O(logn), sc = O(1)