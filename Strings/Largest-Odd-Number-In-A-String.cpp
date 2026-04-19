// problem: https://leetcode.com/problems/largest-odd-number-in-string/description/

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        int index = -1;

        int i;

        for (i=n-1; i>=0; i--) {
            if (i >= 0 && num[i] == ' ') {
                i--;
            }

            if (i < 0) {
                break;
            }

            if ((num[i] - '0') % 2) {
                index = i;
                break;
            }
        }

        i = 0;

        while (i <= index && num[i] == '0') {
            i++;
        }

        return num.substr(i, index - i + 1);
    }
};
// tc: O(n), sc: O(1)