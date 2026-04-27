/*
problem: Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.
If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.

Example 1

Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
Output: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).

Example 2

Input: mat = [ [0, 0], [0, 0] ]
Output: -1
Explanation: The matrix does not contain any 1. So, -1 is the answer.
*/

// brute 1: linear search for the number of ones in each row and return the index of the row with maximum number of ones
class Solution {
  public:   
  int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int rowIndex = -1, maxi = 0;

        for (int i=0; i<n; i++) {
            int ones = 0; // reset count of ones for each row
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 1) {
                    ones++;
                }
            }

            if (maxi < ones) {
                maxi = ones;
                rowIndex = i;
            }
        }

        return rowIndex;
    }
};
// tc: O(n*m), sc: O(1)

// brute 2: linear search
class Solution {
  public:   
  int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int rowIndex = -1, maxi = -1;

        for (int i=0; i<n; i++) {
            int ones = 0; // reset count of ones for each row
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 1) {
                    ones++;
                }
            }

            if (ones > 0 && maxi < ones) {
                maxi = ones;
                rowIndex = i;
            }
        }

        return rowIndex;
    }
};
// tc: O(n*m), sc: O(1)

// better: binary search
class Solution {
private:
    int lowerBound(vector<int>& arr, int m, int x) {
        int ans = m;

        int low = 0, high = m-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }

        return ans;
    }

public:   
    int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int maxi = 0, rowIndex = -1;

        for (int i=0; i<n; i++) {
            int ones = m - lowerBound(mat[i], m, 1); // ones = total - index of first 1 in row
            
            if (ones > maxi) {
                maxi = ones;
                rowIndex = i;
            }
        }

        return rowIndex;
    } 
};
// tc: O(n*log(m)), sc: O(1)

// optimal: top-right corner traversal approach
class Solution {
public:   
    int rowWithMax1s(vector < vector < int >> & mat) {
        int n = mat.size(), m = mat[0].size();

        int rowIndex = -1;

        int row = 0, col = m-1;

        while (row < n && col >= 0) {
            if (mat[row][col] == 1) {
                rowIndex = row; // potential answer, try to find more 1s
                col--; // move left to find a row with more 1s
            }

            else {
                row++; // this row has no 1s at this col, go down
            }
        }

        return rowIndex;
    }
};
// tc: O(n+m), sc: O(1)