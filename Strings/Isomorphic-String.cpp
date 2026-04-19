// problem: https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length(), m = t.length();

        if (n != m) {
            return false;
        }

        vector<int> m1(256, 0), m2(256, 0);

        for (int i=0; i<n; i++) {
            if (m1[s[i]] != m2[t[i]]) {
                return false;
            }

            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }

        return true;
    }
};
// tc: O(n), sc: O(1)