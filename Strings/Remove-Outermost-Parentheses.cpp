// problem: https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int level = 0;

        string ans = "";

        for (char c : s) {
            if (c == '(') {
                // if level > 0, then this '(' is not the outermost parenthesis
                if (level > 0) {
                    ans += c;
                }

                level++;
            }

            else {
                level--;
                
                if (level > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};
// tc: O(n), sc: O(n)