// problem: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

// keep track of the current depth of the parentheses and update the maximum depth whenever we encounter an opening parenthesis
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, ans = 0;

        for (char c : s) {
            if (c == '(') {
                depth++;
                ans = max(ans, depth);
            }

            else if (c == ')') {
                depth--;
            }
        }

        return ans;
    }
};
// tc: O(n), sc: O(1) where n is the length of the input string