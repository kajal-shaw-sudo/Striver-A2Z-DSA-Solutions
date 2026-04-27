// problem link: https://leetcode.com/problems/find-a-peak-element-ii/description/

/*
problem: A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
 
Example 1

Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
*/

// brute: linear search for the peak element
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int curr = mat[i][j];

                int up = (i > 0) ? mat[i-1][j] : INT_MIN;
                int down = (i < m-1) ? mat[i+1][j] : INT_MIN;
                int left = (j > 0) ? mat[i][j-1] : INT_MIN;
                int right = (j < n-1) ? mat[i][j+1] : INT_MIN;

                if (curr > up && curr > down && curr > left && curr > right) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};
// tc: O(m*n), sc: O(1)

// optimal: binary search on columns
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            // find row with max element in this column
            int maxRow = 0;

            for (int i=0; i<m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // check left and right neighbors
            int left = (mid > 0) ? mat[maxRow][mid-1] : INT_MIN;
            int right = (mid < n-1) ? mat[maxRow][mid+1] : INT_MIN;

            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow, mid};
            }

            else if (mat[maxRow][mid] < right) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};
// tc: O(m*log(n)), sc: O(1)