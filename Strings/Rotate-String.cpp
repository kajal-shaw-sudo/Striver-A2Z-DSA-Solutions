// problem: https://leetcode.com/problems/rotate-string/description/

// brute (rotate string by i positions and compare with goal)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();

        if (n != m) {
            return false;
        }

        for (int i=0; i<n; i++) {
            // rotate string to the right by i positions
            string rotated = s.substr(n-i) + s.substr(0, n-i);

            if (rotated == goal) {
                return true;
            }
        }

        return false;
    }
};
// tc: O(n^2), sc: O(n)

// optimal (check if goal is a substring of s+s)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length(), m = goal.length();

        if (n != m) {
            return false;
        }

        string doubleS = s + s;

        return doubleS.find(goal) != string::npos;
    }
};
// tc: O(n), sc: O(n)
