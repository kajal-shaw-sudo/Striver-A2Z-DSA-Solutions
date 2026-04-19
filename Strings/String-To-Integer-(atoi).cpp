// problem: https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int sign = 1;
        int i = 0;
        long long ans = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i == n) {
            return 0;
        }

        if (s[i] == '-') {
            sign = -1;
            i++;
        }

        else if (s[i] == '+') {
            i++;
        }

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            if (sign * ans > INT_MAX) {
                return INT_MAX;
            }

            if (sign * ans < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return sign * ans;
    }
};
// tc: O(n), sc: O(1) where n is the length of the input string