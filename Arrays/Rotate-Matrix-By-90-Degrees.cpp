// problem: https://leetcode.com/problems/rotate-image/description/

// brute
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> rotated(n, vector<int> (n, 0));

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                rotated[j][n-1-i] = matrix[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                matrix[i][j] = rotated[i][j];
            }
        }
    }
};
// tc: O(n^2), sc: O(n^2)

// optimal (transpose + reverse)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        } 
    }
};
// tc: O(n^2), sc: O(1)